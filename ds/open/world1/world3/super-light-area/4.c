inherit ROOM;
void create()
{
      set("short","�W�E���l�m�߳��y��Űϡz");
      set("long",@LONG
�o�̪��O���s�⤬�ۤ��R�ޥ����a��A�b�o�̦��\�h�O��������A��
�ޥ����q��(computer)�A�����۳\�h�q�l���A����W�s�⥿�b�X�O�P��
�m�P�ۡA�Ʊ�ভ��ɨ�׷����j��C
LONG);
set("exits",([
     "east":__DIR__"3.c",
]) );
        set("world", "future"); 
set("objects", ([
__DIR__"obj/computer.c"  :1,
__DIR__"npc/lv4_guard":   4,
]) );
setup();
}
void init()
{
        add_action("do_push","push");
}

int do_push(string arg)
{
        object me;
        me=this_player();
        if(!arg || arg!="1" ) return 0;
        message_vision("$N����b�q���W�I�ù��@�U, �������Ѯ����b�o�өж��F�C \n",me);
        me->move(__DIR__"weapon.c");
          tell_room(environment(me),me->query("name")+"�����l��M�b�o�̱ƦC��ܥX�ӡC\n",me );
        return 1;
}

