int disp_menu1()
{
	FILE *fmenu;
	char ch;
	fmenu= fopen("menu8.txt", "r");
	while((ch=fgetc(fmenu))!=EOF)
	{
		printf("%c",ch );
	}
	return 0;
}