
function start() {
    var canvas = document.getElementById("glcanvas");
    canvas.width = window.innerWidth;
    canvas.height = window.innerHeight;

    //let gl = InitWebGL(canvas);
    const gl = canvas.getContext('webgl2');
    const program = gl.createProgram();

    const vertexShaderSource = `#version 300 es
    #pragma vscode_glsllint_stage: vert
    
    void main()
    {
        gl_Position = vec4(0.0, 0.0, 0.0, 1.0);
        gl_PointSize = 10.0;
    }`;

    const fragmentShaderSource = `#version 300 es
    #pragma vscode_glsllint_stage: frag
    
    precision mediump float;
    out vec4 fragColor;
    
    void main()
    {
        fragColor = vec4(1.0, 0.0, 0.0, 1.0);
    }`;

    const vertexShader = gl.createShader(gl.VERTEX_SHADER);
    gl.shaderSource(vertexShader, vertexShaderSource)
    gl.compileShader(vertexShader);
    gl.attachShader(program, vertexShader);

    const fragmentShader = gl.createShader(gl.FRAGMENT_SHADER);
    gl.shaderSource(fragmentShader, fragmentShaderSource)
    gl.compileShader(fragmentShader);
    gl.attachShader(program, fragmentShader);

    gl.linkProgram(program);
    if (!gl.getProgramParameter(program, gl.LINK_STATUS))
    {
        console.log(gl.getShaderInfoLog(vertexShader));
        console.log(gl.getShaderInfoLog(fragmentShader));
    }

    gl.useProgram(program)

    gl.drawArrays(gl.POINTS, 0, 1);


}

function InitWebGL(canvas) {
    let gl = null;

    try {
        gl = canvas.getContext("webgl");
        gl.viewport(0, 0, window.innerWidth, window.innerHeight);
    } catch (e) {
    }

    if (!gl) {
        alert("Unable to initialize WebGL. Your browser may not support it.");
        return  null;
    }

    return gl;
}

function DrawScene(gl)
{
}

function DrawCharacterEjik(gl)
{
}