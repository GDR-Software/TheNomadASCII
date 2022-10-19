#include "n_shared.h"
#include "n_bff.h"

#ifdef NOMADMAIN
#include "g_scf.h"
#endif

static int filelength(const std::string filename) 
{
	struct stat	buffer;
	if (stat(filename.c_str(), &buffer) == 0) {
		return buffer.st_size;
	}
	else {
		return 0;
	}
}

void I_writeFile(const char* filename, char* data[1080])
{
#ifdef NOMADMAIN
	if (filelength("../Files/gamedata/" + filename) != 0) {
		remove("../Files/gamedata/" + filename);
	}
	std::ofstream file("../Files/gamedata/" + filename);
#elif MAPMAKER
	if (filelength("../Files/" + filename) != 0) {
		remove("../Files/" + filename);
	}
	std::ofstream file("../Files/" + filename);
#endif
	if (file.fail()) {
#ifdef (NTESTBUILD || NDEBUG) && NOMADMAIN
		gameError(FILE_WRITE_OPENING_FAILED);
#else
		error(FILE_IO_FAILED);
#endif
	}
	int size = sizeof(data) / sizeof(data[0]);
	for (int i = 0; i < size; i++) {
		file << data[i] << '\n';
	}
}

void I_writeBFF(const char* filename, char* data[1080])
{
	if (filelength("../Files/gamedata/" + filename + ".bff") != 0) {
		remove("../Files/gamedata/" + filename + ".bff");
	}
	std::ofstream bff("../Files/gamedata/" + filename + ".bff");
	int size = sizeof(data) / sizeof(data[0]);
	for (int i = 0; i < size; i++) {
		bff << data[i] << '\n';
	}
}

char** I_readBFF(const char* filename)
{
	std::ifstream bff("../Files/gamedata/" + filename + ".bff");
	char* buffer[filelength("../Files/gamedata/" + filename + ".bff")];
	std::string line;
	int a = 0;
	while (std::getline(bff, line)) {
		buffer[a] = (char*)line;
		a++;
	}
	return buffer;
}

#ifdef _G_SCFREAD_
void I_writeSCF(void)
{
	if (filelength("../Files/gamedata/nomad.main.scf") != 0) {
		remove("../Files/gamedata/nomad.main.scf");
	}
	std::ofstream scf("../Files/gamedata/nomad.main.scf");
	for (int i = 0; i < )
	int size = sizeof(data) / sizeof(data[0]);
	for (int i = 0; i < data.size(); i++) {
		scf << data[i] << '\n';
	}
}

char** I_readSCF(void)
{
	std::ifstream scf("../Files/gamedata/nomad.config.scf");
	char* buffer[filelength("../Files/gamedata/nomad.config.scf")];
	std::string line;
	int a = 0;
	while (std::getline(scf, line)) {
		buffer[a] = (char*)line;
		a++;
	}
	return buffer;
}
#endif

#ifdef NOMADMAIN
void I_writeNGD(const char* svname, char* data[1080])
{
	if (filelength("../Files/gamedata/" + svname + ".ngd") != 0) {
		remove("../Files/gamedata/" + svname + ".ngd");
	}
	int size = sizeof(data) / sizeof(data[0]);
	std::ofstream ngd("../Files/gamedata/" + svname + ".ngd");
	for (int i = 0; i < size; i++) {
		ngd << data[i] << '\n';
	}
}

char** I_readNGD(const char* svname)
{
	std::ifstream scf("../Files/gamedata/" + svname + ".ngd");
	char* buffer[filelength("../Files/gamedata/" + svname + ".ngd")];
	std::string line;
	int a = 0;
	while (std::getline(scf, line)) {
		buffer[a] = (char*)line;
		a++;
	}
	return buffer;
}
#endif