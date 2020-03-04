inherit ROOM;
void create()
{
        set("short", "��s");
        set("long",@LONG
�A��F��s�����O�L���A�o�̪K���Z�K���O�B�ѡA�۵M��
�;��D�`���k�A���䪺�V�����q�L��A�ݨӷ��������A�V���W
�y�U�@�D�s�u�A�F�F���nť�ӵκZ���w�A�Ӧb�A�����e�観�@
���s���A�ݨӰ��q�L��n�k���i��ݭn�ܰ����i��C
LONG
        );
  
set("exits", ([
  "westup" : __DIR__"mu20", 
]) );
set("item_desc", ([
    "�s�u" : "���۱V���۵M��X���u�A�Y�����ܥi�H��(drink)�C\n",
    "�s��" : "�@���ݨӫD�`�ƪ����s���A���H�ߪ��H�i�H�k��(climb)�ݬݡC\n",
]));
set("objects",([__DIR__"animal/wolf" : 3,]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}
  
void init()
{
  add_action("do_drink","drink");
  add_action("do_climb","climb");
}

 int do_drink(string arg)
{
        object me;
        if( !arg || arg!="�s�u" ) return notify_fail("�A�n�ܤ���F��?\n");
        me=this_player();
       if(query("water") > 500)
        {
        return notify_fail("�u���N�n���U�F�A�٬O�����^�_�ɦA���a�I�C\n");
        }
        else 
        {
        message_vision("$N�ܤF�@�f�u���Aı�o���믫�h�F�C\n",me);
        me->receive_heal("hp",me->query("max_hp")/15);
        me->receive_heal("ap",me->query("max_ap")/15);
        me->receive_heal("mp",me->query("max_mp")/15);
        add("water",1);
        return 1;
        }
}

int do_climb(string arg)
{
        object me=this_player();        
        if(arg!="�s��") 
                return notify_fail("�A�Q�n�k��(climb)����H");
        if(me->is_busy() || me->is_fighting() )
                return notify_fail("�A�����ۡA�L�k�M�����I���ʧ@�C\n");
        if(me->query_skill("dodge",2) <50)
                return notify_fail("�A�����\\�y�ڤ����A�A�L�k�w���a���L�h�C\n");
        if(!me->move(__DIR__"musun.c") )
                return notify_fail("�A�L�k�k���W�h�C\n");
        message_vision("$N�ϥX�¼������\\���������F�W�ӡC\n",me);
        return 1;
}

void reset()
{
  set("water",0);
  ::reset();
}










