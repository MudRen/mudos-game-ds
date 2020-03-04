// Room: /open/world1/tmr/bagi/hole.c

inherit ROOM;

void create()
{
        set("short", "�s�}");
        set("long", @LONG
�A���b�@�B���i�e�ǤG�B�T�H���p�s�}�A�A�@���o�{�s�}�ɳB���ۤ@
���e���A�ݨ䨭�W�G�ꤣ������A�A�i�����H�w���`�h�~�F�C
LONG
        );
        set("light", 1);
        set("world", "past");
        set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"glade",
]));
        set("item_desc", ([ /* sizeof() == 1 */
             "�e��" : "�@�㦭�w���\\���e���A�ݨ䰩�f�����A���G�O�ӪZ�L�e���H�I\n",
        ]));
        set("no_clean_up", 0);

        setup();
}

int i=0;

void init()
{
        add_action("do_search","search");
}

int do_search(string arg)
{
        object me,book;
        me=this_player();
        if(!arg || arg!="�e��") return 0;
	message_vision("$N�J�Ӧa�j�F�j�e��...\n",me);
        if(i==0) {
        i=1;
        book=new(__DIR__"npc/obj/bagibook");
        book->move(me);
           tell_object(me,"�A���G�j��F�@���ѡH\n");
         return 1;
        }
        else return notify_fail("�A�èS���o�{�줰��F��C\n");
        return 1;

}
