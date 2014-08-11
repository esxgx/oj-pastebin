#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#include <fcntl.h>

char header[] = "/*\n"
	"ID:esxgx1\n"
	"LANG:C++\n"
	"PROG:";
char tailer[] = "\n"
	"*/\n"
	"#include <cstdio>\n"
	"#include <cstring>\n"
	"#include <iostream>\n"
	"#include <algorithm>\n"
	"using namespace std;\n\n"
	"int main(void)\n"
	"{\n"
	"\t#ifndef ONLINE_JUDGE\n"
	"\tfreopen(\"in.txt\", \"r\", stdin);\n"
	"\t#endif\n"
	"\n"
	"\treturn 0;"
	"\n"
	"}\n";

char tmpl[MAX_PATH + sizeof(header) + sizeof(tailer) - 1];

int main(void)
{
	char progname[MAX_PATH];
	printf("Prog2gen:");scanf("%s", progname);
	sprintf(tmpl, "%s%s%s", header, progname, tailer);
	strcat(progname, ".cpp");
	int fd = open(progname, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd >= 0) {
		write(fd, tmpl, strlen(tmpl));
		close(fd);
	}
	printf(tmpl);
	return 0;
}
