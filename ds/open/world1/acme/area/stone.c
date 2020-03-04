// Room: /u/a/acme/area/stone.c

inherit ROOM;

void create()
{
	set("short", "�۫�");
     set("light",1);
	set("long", @LONG
�o�̪ſ������A����F��]�S���A�|��O�ѥ���Һc�����A�b�J�f��
�����a��A�����������۪F��b�o���C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"rock",
]));
	set("no_clean_up", 0);

     set("item_desc", ([
     "�۾�" : "�A�J���@�F�@�۾��A�o���۾����Ӥp�}�A���Y���ӪF��b�o���C\n",
    "�p�}" : "�A�J���@�F�@�p�}�A���Y���@�Ӳy�b�o���C\n",
     ]) );
	setup();
}

int do_search(object me,string arg)
{
        object pearl;
        if( arg == "�۾�" )
        {
         write("�۾��W���Ӥp�}�C\n");
         return 1;
        }
        if(arg != "�p�}" && arg != "hole" ) return 0;
        if(query_temp("getpearl")) return notify_fail("�A�b�p�}�̺N�F�N, ���O�o�S����줰��C\n");
	
    message_vision("$N�N�F�N�p�}�A��M���X�F�@���]���]�C\n\n",me);
        pearl=new(__DIR__"npc/obj/pearl.c");
        pearl->move(me);
        set_temp("getpearl",1);
        set("item_desc", ([
     	"�۾�" : "�A�J���@�F�@�۾��A�o���۾����Ӥp�}�C\n",
    	"�p�}" : "�A�J���@�F�@�p�}�A�̭��ŪŪ����򳣨S���C\n",
     	]) );
set("long", @LONG
�o�̪ſ������A����F��]�S���A�|��O�ѥ���Һc�����A���㪺�a
�W�ٯd�F�@�Ƿs�}�L�C
LONG
);
	set("light",0);
        call_out("delay",600,this_object());
        return 1;
}

void delay(object room)
{
 delete_temp("getpearl");
      set("light",1);
	set("long", @LONG
�o�̪ſ������A����F��]�S���A�|��O�ѥ���Һc�����A�b�J�f��
�����a��A�����������۪F��b�o���C
LONG
	);
     set("item_desc", ([
     "�۾�" : "�A�J���@�F�@�۾��A�o���۾����Ӥp�}�A���Y���ӪF��b�o���C\n",
    "�p�}" : "�A�J���@�F�@�p�}�A���Y���@�Ӳy�b�o���C\n",
     ]) );
     return;
}
