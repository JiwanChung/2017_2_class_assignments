program ass0;

uses classes, sysutils;

var
	InputFile: TextFile;
	s: string;
begin
	AssignFile(InputFile, 'input.txt')
	reset(InputFile);
	readln(InputFile);
	writeln('Text: ', s)
end.
