#version 330

out vec4 FragColor;
in vec2 coord;

void main() {
    vec2 sommati = vec2((coord.xy + 1.0) * 4.0);
    float checker = mod(floor(sommati.x) + floor(sommati.y), 2.0);
    vec3 color = mix(vec3(0.0), vec3(1.0), checker);

    FragColor = vec4(color, 1.0);
}
