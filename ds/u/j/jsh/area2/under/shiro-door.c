#include <ansi.h>
inherit ROOM;

void show(object me) ;
void create()
{
        set("short", HIR"�ɫ̪��e"NOR);
        set("long", @LONG
�A�Ө�@�����j���ɪ��e�A�ɪ����������観�@�c�]���A���O�o
������A�]���]�����k�������F�A�j�p����]���c�]�����t���h�A�B
�O�����k�X�A���H���͵L���p�Q�A�p�G�����̭��A�����D�|����
���򪬪p�H 
LONG
        );

        set("item_desc",([
    "���}":"�]�����k���A�]�ʲ��y�A�ҥH�e�{�X�@�Ӳ`�}�A���G�i�H�񤰻�i�h�H(put someone in hole)\n",
        ]) );
        set("exits", ([ /* sizeof() == 1 */
          "up" : __DIR__"startroom",
        ]));
        set("world", "past");
        set("
no_clean_up", 0);  
    setup();
}
void init()
{
        add_action("do_put","put");
}

int do_put(string arg)
{
        object me,eye;
        me=this_player();
 
      if(!arg || arg!="eye in hole") return notify_fail("�A�n�񤰻�?\n");
      if(!objectp(eye=present("evil eye",me) ) ) 
                return notify_fail("�A�S���o���F��� ? \n");
     message_vision(HIW"$N"HIR"�x�Ԥ��媺�N�c�]������i���}��\n\n"NOR,me);  
     message_vision(HIR"�@�}�H�S�n�T�q�c�]���ǥX�A�c�]�������F�L�ӡA�äƧ@�@�D�������F�ѻڡI\n\n"NOR,me);     message("world:world1:vision",HIW"\t\t�@�D"HIR"����"HIW"�q�a�U�ӥު��`�B�Q�X�I�I\n"  
                                   HIG"\n\t\t\t    �y"HIR"��ù��"HIG"�z\n"  
                                   HIW"\n\t\t\t    �}�ҡE�E�E�E�E\n"NOR,users());  
     message_vision(HIM"�A�Q�l�J�F����\n"NOR,me);    
        me->start_busy(5); 
        call_out("show",3,me);
        return 1;        
}

void show(object me)
{ 
        tell_object(me,"�A�����κ������E�C\n"); 
        me->move(__DIR__"start_shiro");  
        tell_room(environment(me),me->query("name")+"��M�X�{�b�A�����e�C\n",me);
        return;
}
