// frag_desktop_header.glsl ? standalone header for full blackhole.glsl
// Composed with blackhole.glsl body + main() wrapper at build time.
#version 330

// === Standard Shadertoy-style uniforms ===
uniform vec3 iResolution;
uniform float iTime;
uniform vec4 iDate;

// === Desktop screen texture (DXGI capture -> OpenGL, replaces Ghostty terminal) ===
uniform sampler2D iChannel0;

// === Ghostty compatibility uniforms (dummy - not used by MODE_DEMO) ===
uniform vec4 iCurrentCursorColor = vec4(0.0);
uniform vec4 iPreviousCursorColor = vec4(0.0);
uniform float iTimeCursorChange = 0.0;
uniform vec4 iMouse = vec4(0.0);

// Note: B_CRIT, WORK_PERIOD_MIN, BREAK_MIN, IDLE_FADE_SEC, TIME_SCALE,
// TOKEN_LEVEL are all defined inside blackhole.glsl - do NOT redeclare here.

// === Output (compatibility profile) ===
#define fragColor gl_FragColor
