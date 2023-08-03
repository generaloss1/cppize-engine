#version 330

layout(location = 0) in vec2 a_pos;
layout(location = 1) in vec2 a_uv;
layout(location = 2) in vec4 a_color;

out vec4 color;
out vec2 uv;

uniform mat4 u_projection;
uniform mat4 u_view;

void main(){
    gl_Position = u_projection * u_view * vec4(a_pos, 0.0, 1.0);
    uv = a_uv;
    color = a_color;
}