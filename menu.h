int disp_menu()
{
	FILE *fmenu;
	char ch;
	fmenu= fopen("menu9.txt", "r");
	while((ch=fgetc(fmenu))!=EOF)
	{
		printf("%c",ch );
	}
	return 0;
}