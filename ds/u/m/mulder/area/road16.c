// Room: /u/m/mulder/area/road16.c

inherit ROOM;
inherit MOBROOM; 
void create()
{
	set("short", "�o����");
	set("long", @LONG
���ߧA��I�A�i��άO�L�٨S�X�Ӫﱵ�A�D�A�O�s�⪺�A��
�A�֨Ǩ��աA�Y�M�A�X�Ӫ��ܨ��N�֤]��������A�A�A�u�n�V�A
���B�ͻ��@�n�G�u�A����I�v
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road13",
]));
	set("no_clean_up", 0);
	set("light",1);
	set("chance",100);
	set("mob_amount",3);
	set("mob_object",({
	"/u/m/mulder/area/npc/mask",
	"/obj/example/dog",
	}) );
	setup();
	
}
void init()
{
	::init();  
        add_action("d_creat","creat");	        
        add_action("d_stop","stop");
}

int d_stop(string arg)
{
 this_object()->set_temp("stop_creat",1);
 tell_object(this_player(),"�Ǫ��a�p�w����!\n");
 return 1;
}

int d_creat(string arg)
{
 this_object()->set_temp("stop_creat",0);
 tell_object(this_player(),"�Ǫ��a�p�w�}��!\n");
 return 1;
}
