inherit ROOM;
void create()
{
	set("short", "��f");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_8_8",
	]));
       set("where","batogiya_dtl");
         set("no_fight" , 1);
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

