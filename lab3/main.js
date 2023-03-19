
function start() {
    var canvas = document.getElementById("glcanvas");
    canvas.width = window.innerWidth;
    canvas.height = window.innerHeight;

    let ctx = InitWebGL(canvas);
    DrawScene(ctx);
}

function InitWebGL(canvas) {
    let gl = null;

    try {
        gl = canvas.getContext("2d");
    } catch (e) {
    }

    if (!gl) {
        alert("Unable to initialize WebGL. Your browser may not support it.");
        return  null;
    }

    return gl;
}

function DrawScene(ctx)
{
    ctx.fillStyle = "rgb(0, 0, 0)";
    ctx.fillRect(0, 0, window.innerWidth, window.innerHeight);
}