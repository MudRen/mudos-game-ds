#include <ansi.h>
#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
        if(!arg) {
                message_vision(HIC+me->name()+"���|���� �q�ѤW���U�@�D�{�q�N���b�A���e�@���ت��a��I\n"NOR, me);
                return 1;
        }
        
        ob = present(arg, environment(me));
        if (!ob) return notify_fail("�䤣��o�ӥͪ�.\n");
        if( userp(ob) ) return notify_fail("�o�ӫ��O����Φb���a���W�C\n");

        message_vision("$N���|����j�� �h���a�I�I �u���ѤW�@�D�{�q�������ʦa����$n�A�N���Ƭ��@����u...\n", me, ob);
        ob->set_temp("temp/death_type","[���p����]"); 
        ob->die();
        return 1;
}
 
int help(object me)
{
   write(@HELP
���O�榡: smash <�ͪ�>
 
���@�ӥͪ��ߨ覺�`(die).

HELP
   );
   return 1;
}

