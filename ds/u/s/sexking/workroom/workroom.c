#include <ansi.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIG"��g�Z��"NOR);
        set("long", @LONG
�o�̬O�@���ܯ䪺�Z��..�A�o���ְk�]�~�棬..
LONG 
);
        set("exits", ([ /* sizeof() == 2 */
       "east" : __DIR__"workroom3",
        set("item_desc",([
        "��g����":"�@�ӫܯ䪺����,���G�ܤ[�S�R���ˤl��C\n",
        "��g������s":"�ѩ�o�̹�b�ӯ�F��A�Ԥ���Q��(push)�U�R��(���s)�C\n",
        ]) );
        set("light",1);
        set("no_clean_up", 0);
        set("no_recall",1);
        set("no_kill",1);
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
        if (!arg || arg!="���s") return 0;
        message_vision(HIY"$N���Y��M�Q�l�차���,�n�ޣ��I�C\n"NOR,me);
        me->move("/d/wiz/hall1");
        return 1;
}



inherit ROOM;
void show(object me);
void create()
{
        set("short",HIR"��g����"NOR);
        set("long",@LONG
�o�̬Osexking���a���f�A�ڻ�sexking�O�@�ӫܧ�
�g���H�A�ҥH�s�@��g�����A���Lsexking���F��
�]���\�h�H��g�ҥH�]�F�������H�L�k�i�ӡC
LONG
);

        set("item_desc",([
        "��g�q�a":"�o�O�@�ӫܥi�R���q�a�A���A�Ԥ���Q��(push)�ݬݡC\n",
        "��g����":"�o�O�@�ӫܦn�������A����������A�ݤF�Nı�o�n�n���A�Ԥ���Q�I(touch)�ݬݡC\n",
        ]) );
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_touch","touch");
        add_action("do_push","push");
}

int do_touch(string arg)
{
        object me;
        me=this_player();
        if(!arg || arg!="��g����") return 0;
     message_vision(HIR"$N��g���N�F�@�U���A��M��g�����i�j�F�L�ڱN$N�l�F�i�h�C\n"NOR,me);
     me->delete_temp("the-door");
     me->move(__DIR__"door");
        me->start_busy(4);
        call_out("flop1",3,me);
        return 1;        
}

void flop1(object me)
{
        if(!me) return;
if (me->query_temp("fly-sky")==1) return 0;

        tell_object(me,HIM"�A��M�q��g�����u�F�X�ӡA�Q���T�V���ˤl�C\n");
        me->move(__DIR__"workroom2");
        tell_room(environment(me),me->query("name")+"��M�q��g�����u�F�X�ӡA�Q���T�V���ˤl�C\n"NOR,me);
        return;
}
int do_push(string arg)
{
        object me;
        me=this_player();
        if(!arg || arg!="��g�q�a") return 0;
     message_vision(HIG"$N��g�����F�@�U��g�q�a�A��M�_�X�F�@�b�p�����H�G�N�A$N�]�F�_�ӱN$N�Ϩ�F�ѤW�C\n"NOR,me);
     me->delete_temp("the-sky");
     me->move(__DIR__"sky");
        me->start_busy(4);
        call_out("flop2",3,me);
        return 1;        
}
void flop2(object me)
{
        if(!me) return;
if (me->query_temp("fly-sky")==1) return 0;

        tell_object(me,HIC"�A�������L��a�W�A�^�ӥ|�}�¤ѡA���Ѹ~�F�@�j���_�ӡC\n");
        me->move(__DIR__"workroom2");
        tell_room(environment(me),me->query("name")+"�������L��a�W�A�^�ӥ|�}�¤ѡA���Ѹ~�F�@�j���_�ӡC\n"NOR,me);
        return;
}
