// Room: /u/d/darkfool/area1/13.c

inherit ROOM;

void create()
{
	set("short", "��D���Y");
	set("long", @LONG
�o�̬O��D�����Y�A��v�Ϧb�A���_�褣���B�A���o�̦��G�S��
���i�H�q�L�h�A�A���F�観�l�p�ΡC
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"12",
]));

	setup();
}
void init() 
{
	add_action("usecomp","use");
}
int usecomp(string  arg)
{
	object me;
	me=this_player();
	if(arg != "computer") return 0;
	 else {
	 	message_vision(
	 	"����a�@�n�}�F\n\n"
	 	,me);
	         set("exits",([
	        "west" : __DIR__"12",
	        "house" :__DIR__"a1",
	        ]));
	        return 1;
	       }
}	
	 	