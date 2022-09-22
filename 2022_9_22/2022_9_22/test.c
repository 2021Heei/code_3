#define _CRT_SECURE_NO_WARNINGS 1
#include <Windows.h> 
#include <dsound.h>
#pragma comment (lib,"dsound.lib")

LPDIRECTSOUNDBUFFER bf; DSBUFFERDESC dsd; LPDIRECTSOUND snd; DWORD wfm[5] = { 0x10001,0xac44,0x15888,0x100002,0 };
int pb(HWND h, void* d, int sz) {
	void* plb = 0; unsigned long dsz = 0; 
	DirectSoundCreate(0, &snd, 0);
	snd->SetCooperativeLevel(h, 1); 
	dsd.dwSize = sizeof(dsd);
	dsd.dwFlags= 98688;
	dsd.dwBufferBytes = sz;
	dsd.lpwfxFormat = (WAVEFORMATEX*)wfm; 
	dsd.dwReserved = 0; 
	snd->CreateSoundBuffer(&dsd, &bf, 0); 
	bf->Lock(0, sz, &plb, &dsz, 0, 0, 0); 
	memcpy(plb, d, dsz);
	bf->Unlock(plb, dsz, 0, 0);
	bf->Play(0, 0, 1);
	return 1;
}
typedef struct {
	double s[2048];
	int size; 
	int c;
}LTI;

LTI lti[32]; 
int clr = 0;
unsigned long long sd;
double rd() { 
	return((sd = sd * 764261123 + 1) & 65535) / 32768.0 - 1;
}
double bfq[] = { 27.5,29.13,30.86,32.7,34.648,36.71,38.89,41.2,43.65,46.24,49,51.91 }; unsigned char dt[] = "YC4MNQw6DEEMP4CQPGA4gSAiDCkMLgw1DDOAkDBgLIEgMQQ9XDAEPFwsBDhcKQQ1XCUAGWAkABhgIAAUYBsAD2AdABGBgDUwOCseBToAIgQlX\
DowPSsgBT8AJAQnXEEwRCsiBUEAJQQpXD8wPSsgBToAJQQpXEEwPyseBToAIgQlXEEwPysgBToAJAQnXDhgNQAWMB0wIjAkMCVgNTA4MDoAHjAiMDoAJTA9MD8AIDAkMEEAJzBEMEEAIjAlMD8A\
KTA9MDoAIDAlMEEAKTA/MDoAHjAiMEEAJTA/MDoAIDAkMDgAJ2A6ACIwKTAuMDAwMWApADUwLAA4MC4AEgQxBDYEOiQZMB4wLAA4MC4AFAA6MBswMAAgADwwLAA4MC4AFgA6MB0wLAAiADgwJwA\
zMCkAEQA1MBgwKQAdADUwLAA4MC4AEgQxBDYEOiQZMB4wLAA4MC4AFAA6MDEAGwA9MDAAIAA8MCwAODApABYELgQxBDUkHTApACIALgAzYDAAEQApADUwGDApAB0ANTAsADgwOgASAC4wGTAeMC\
wAODAuABQAOjAbMDAAIAA8MCwAODAuABYAOjAdMCwAIgA4MCcAMzApABEANTAYMCkAHQA1MCcAMzAiABIALjAZMCkAHgA1MCcAMzAiABQALjAbMCwAIGAuABYAIjAdMCIwJDAlYDUEQSw4BEQsO\
gASBEYMGRAeECIQJRAqEC4QKhAlEDgAIgREDB4QGRA6ABQERgwYEBsQIBAkECcQPAAsBEgMJxAkEDgAIAREDBsQGBA6ABYERgwdECIQJRApEC4QOAAxBEQMLhApEDMAJQQ/DCIQHRA1ABQEQQwb\
ECAQJBAnECwQNQAwBEEMLBAnEDgAJAREDCAQGxA6ABIERgwZEB4QIhAlECoQLhAqECUQOAAiBEQMHhAZEDoAFARGDBgQGxA9ACAESQwkECcQPAAsBEgMJxAkEDgAIAREDBsQGBA1ABYEQQwZEB0\
QIhAlECkQMQAuATUBOgE9DSkQJRAiEB0QGRAwABQBMwE4ATwNGBAbECAQJBAnEDUALARBDCcQJBA4ACAERAwbEBgQOgASBD0EQgRGBBkQHhAiECUQKhAuECoQJRA4ACIERAweEBkQOgAUBEYMGB\
AbECAQJBAnEDwALARIDCcQJBA4ACAERAwbEBgQOgAWBD0EQQRGBB0QIhAlECkQLhA4ADEERAwuECkQMwAlBD8MIhAdEDUAFARBDBsQIBAkECcQLBA1ADAEQQwsECcQMwAkBD8MIBAbEC4AEgQ6D\
BkQHhAiECUQKhA1AC4EQQwqECUQMwAiBD8MHhAZEC4AFAQ6DBgQGxAgECQQJxA4ACwQJxAkECAQGxAYEC4AFgA6EBkQHRAiECQQJRApECUQIhAlECkQLBAuEDAQMRA1MDUEQSwzBD8nHgUuACIEO\
gAlXDUEQSwzBD8nIAUuACQEOgAnXDgALGAuACIAOjAdMCIwJDAmgMA2ACAGOgY9BkEeGzAgMCIwJIDANQAiBjoGPAZBHh0wIjAkMCaAwDYAIAY6Bj0GQR4bMCAwIjAkgMAuABYAIgY1BjoGQQZG"
,dt2[2048]; 
void t(int k) {
	int i, t = k;
	double f = bfq[k % 12]; 
	while (t) {
		f *= 2;
		t /= 12;
	}
	f *= 2; 
	lti[clr].size = (int)(44100 / f); 
	for (i = 0; i < lti[clr].size; i++) {
		lti[clr].s[i] = rd();
	}lti[clr++].c = 0; clr %= 32;
}double reverb() {
	int i; double sum = 0; for (i = 0; i < 32; i++) {
		int c = lti[i].c, s = lti[i].size; 
		if (!s)
			continue;
		sum += lti[i].s[c]; lti[i].s[c] = (lti[i].s[c] * 0.88 + lti[i].s[(c + s - 1) % s] * 0.12) * 0.995; lti[i].c++; 
		lti[i].c %= s;
	}
	return sum / 5;
}
unsigned int b64m(unsigned int ch){
	if (ch == 43)
		return 62; 
	if (ch == 47)
		return 63;
	if (ch == 61)
		return 64;
	if ((ch > 47) && (ch < 58))
		return ch + 4; 
	if ((ch > 64) && (ch < 91))
		return ch - 'A';
	if ((ch > 96) && (ch < 123))
		return(ch - 'a') + 26; return 0; 
	}

unsigned int b64d(unsigned char* in, int l, unsigned char* out) {
	int i, j = 0, k = 0, s[4];
	for (i = 0; i < l; i++) {
		s[j++] = b64m(*(in + i));
		if (j == 4) {
			out[k + 0] = ((s[0] & 255) << 2) + ((s[1] & 0x30) >> 4);
			if (s[2] != 64) {
				out[k + 1] = ((s[1] & 0x0F) << 4) + ((s[2] & 0x3C) / 4);
				if ((s[3] != 64)) {
					out[k + 2] = ((s[2] & 0x03)<< 6) + (s[3]);
					k += 3;
				}
				else { k += 2; }
			}
			else { k += 1; }j = 0;
		}
	}
	return k;
}

unsigned short pcm[7938000]; 
int wcr; 

int main() {
	int sz = b64d(dt, sizeof(dt), dt2), oft = 0;
	int wt = 0, sc, i;
	while (oft < sz) {
		if (dt2[oft] & 0x80)wt = ((dt2[oft] & 0x7f) << 8) + dt2[oft + 1], oft += 2;
		else wt = dt2[oft++];
		sc = (int)(wt * 380);
		for (i = 0; i < sc; i++) {
				pcm[wcr++] = (unsigned short)(reverb() * 32767);
		}
		t(dt2[oft++]);
	}
	sc = 44100 * 6; for (i = 0;
		i < sc; i++) { pcm[wcr++] = (unsigned short)(reverb() * 32767); 
	}
	pb(GetConsoleWindow(), pcm, wcr * 2); 
	Sleep((DWORD)(wcr / 44.1));
}