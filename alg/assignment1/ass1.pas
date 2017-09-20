program ass1;

uses 
	classes, sysutils;
const
	IFileName = 'input.txt';
	OFileName = 'output.txt';
var
	Instream, Outstream:TFilestream;
BEGIN
if FileExists(IFileName) then
	begin
	Instream := TFilestream.Create(IFileName, fmOpenRead);
	Outstream := TFilestream.Create(OFileName, fmOpenWrite);
	Outstream.free;
	Instream.free;
	end else writeln('err');
END.

