// Room: /open/world1/tmr/advbonze/hill17.c

inherit ROOM;

int do_jump(string arg);
void create()
{
        set("short", "�ⶳ�p��-�ʤf�B");
        set("long", @LONG
�A�����b�W�ѱ誺�@�B�ʤf�B�A���n�Q�ƤV�����a��A�O�t�@�B�q���s�U
���ʤf�B�A�A�{�b�i�H�M���ݨ쩹�_�����B�A�N�O�ⶳ�p���W�����x�A�A���M
�o�{�p�����x�W���M���y�F�Q�H�������j����A�����Ӯg�b����Ϯg�X�ӮɡA
�N�O�b�s�y�B�Ҭݨ쪺�_���A�A�ݵ۬ݵۡA���T�P�Ħ��������C
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
  "�ʤf" : "�@�ӤQ�X�V���e���j�ʤf�A�A�γ\\�|�Q�n��(jump)�L�h�C\n",
]));
        set("no_clean_up", 0);
        set("current_light", 6);
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"summit1",
]));
        set("outdoors", "forest");

        setup();
}
void init()
{
    ::init();
    add_action("do_jump","jump");
}

int do_jump(string arg)
{
       object me=this_player();        

       if(arg!="�ʤf") 
                return notify_fail("�A�Q�n��(jump)�L����H");
        if(me->is_busy() )
                return notify_fail("�A�����ۡA�L�k�M�����I���ʧ@�C\n");
         if(me->query_skill("dodge") <10)
                return notify_fail("�A�����\\�y�ڤ����A�A�L�k�w���a���L�h�C\n");
        if(!me->move(__DIR__"hill16.c") )
                return notify_fail("�A�L�k���L�ʤf�C\n");
        tell_room(environment(me), me->name() + "�@������L�F�ʤf�A�������a���a�W�C\n");
        return 1;
}


