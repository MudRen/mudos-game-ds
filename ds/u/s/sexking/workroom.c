#include <ansi.h>
inherit ROOM;
void show(object me);
void create()
{
        set("short",HIR"��g����"NOR);
        set("long",@LONG
�o�̬Osexking���a���f�A�ڻ�sexking�O�@�ӫܧ�
�g���H�A�ҥH�s�@��g�����A���Lsexking���F��
�]���\�h�H��g�ҥH�]�F�������H�L�k�i�ӡA�H�\
�A�i�H�j�j(search)�ݾ����b���̡C
LONG
);

        set("item_desc",([
        "��g�q�a":"�o�O�@�ӫܥi�R���q�a�A���A�Ԥ���Q��(push)�ݬݡC\n",
        "��g����":"�o�O�@�ӫܦn�������A����������A�ݤF�Nı�o�n�n���A�Ԥ���Q�I(touch)�ݬݡC\n",
        ]) );
        set("outdoors","land");
        set("light",1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
setup();
}
void init()
{
        add_action("do_touch","touch");
        add_action("do_push","push");
        add_action("do_pupu","pupu");
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

        tell_object(me,HIW"�A�������L��a�W�A�^�ӥ|�}�¤ѡA���Ѹ~�F�@�j���_�ӡC\n");
        me->move(__DIR__"workroom2");
        tell_room(environment(me),me->query("name")+"�������L��a�W�A�^�ӥ|�}�¤ѡA���Ѹ~�F�@�j���_�ӡC\n"NOR,me);
        return;
}
int do_pupu(string arg)
{
        object me;
        me=this_player();
        if(arg!="��")
        {
                notify_fail("�A�n�񤰻�?\n");
                return 0;
        }
        if(this_player()->query("id") == "sexking")
        {
        if(me->can_move(__DIR__"workroom4"))
        message_vision(HIG"$N��M��F�ӧ��A��g���j�s����������...�N�Ʀ��@�D���������F�C\n"NOR,me);
             tell_room(environment(me),me->name()+"�񪺧��Q�������A�߱��κZ�F�_�ӡC\n",({me}));
             tell_room(environment(me),me->name()+"�Q�Χ����ħQ�����b�@�˶V�ĶV��....�C\n",({me}));
                        me->move(__DIR__"workroom4");
                        write("�A�������Υ��F�ҥH�N���F�U�ӡC\n");
                        tell_room(environment(me),me->name()+"��M�q�ѤW���ƲM�����F�U�ӡC\n",({me}));
                        return 1;
                } 
                else
                {
                        write(HIC"����..�A�񪺧��ӯ�F..�u���p����񪺤~�O������...�C\n"NOR);
                        return 1;
                }
        } 
// luky's code...
int room_effect(object me)
{
        switch(random(14))
        {
                
         case 3:
         case 2:        tell_object(me,"�A�w�g�Ԥ���Q�n�i�J�o�ӫΤl�̤F..���o�����p��i�J..�C\n");
                        return 1;
         
         case 1:
         case 0:        tell_object(me,"�A��M���@�ة_�S���Pı..�n���������Ʊ��P�C\n");
                        return 1;
default:       return 1;
        }
}

 
