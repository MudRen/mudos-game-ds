inherit ROOM;

void create()
{
        set("short", "�˪L�J�f��");
        set("long", @LONG
�o�̬O�˪L���J�f�A�b�o�̦��G���ۤ����h����Ĭ������A��
�L�n���]�O�٨S�����A�ڻ��Q��Ĭ������Ҫ��۪������A�b�����
���F����]�|�C�C�����h�A�s�s�峣���M���A�o�̪����}�l���I�~�k�A
�O�H���I�����C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"fgo1.c",
  "northwest" : __DIR__"fgo3.c",
]));
        set("no_clean_up", 0);
        set("outdoors","forest"); 
        set("objects",([
  __DIR__"npc/obj/wtree.c" :random(4),
]));
        set("item_desc", ([
                "���}" : "�@�Υ����A���������i�H�ݨ�}�ޡA�n���i�H�i�h���ˤl(enter)�C\n",
                ]));
        setup();
}
void init()
{
        add_action("do_enter","enter");
}

int do_enter(string arg)
{
          object me;
          me=this_player();
          if(arg != "���}")
            return 0;
          else {
            message_vision("$N�w�w�������}���F�i�h�C\n",me);
            me->move("/open/world1/moonhide/area/snake-room");
            return 1;
          }
}

