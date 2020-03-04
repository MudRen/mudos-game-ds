// exchange.c ���n�洫 �������� 
// -Tmr 2002/04/14

#include <ansi.h>

inherit F_CLEAN_UP;

int getCost(string race) {
        switch(race) {
                case "human": return 350;
                case "ogre": return 600;
                case "tiger": return 600;
                case "titan": return 600;
                default: return 500;
        }
        return 500;
}
 
int main(object me, string arg)
{
        object ob;
        int cost;
        seteuid(getuid());
        if(!userp(me) ) return 0;
          if( me->query("level") < 26 )
                  return notify_fail("�A�ܤ֭n26�ťH�W�A�~�ഫ���������C\n");

        cost = getCost( me->query("race") );
        if( me->query("popularity") < cost )
                return notify_fail("�A�èS���������u�n��v�I�ơC\n");
        if( me->is_busy() || me->is_fighting() )
                return notify_fail("�A�����ۡA�S���ŦV�ѯ��洫�F��C\n");
        if(objectp(ob=present("undead_item",me)))
                return notify_fail("�A���W�w�g���@�㫽���F�C\n");


//        if( random(3) )  {
//                ob = new("/open/always/doll2.c");
//        }
//        else 
        ob=new("/open/always/doll.c");

        if( !ob->move(me) )
                return notify_fail("�A���W���F��Ӧh�άO�ӭ��F�C\n");

        message_vision(
        HIC "$N�������q�a���F�U�ӡA�j�n���D�G�u�ڱq�@�o�������A�W�ѤJ�a�W���j�I�I�v\n\n"
        +HIY"$N�y��ı�o�W�Q�p�B����A�ӱy�y�h�y�y�A�@�ߥu�Q�o�۫�������צѨ즺....\n\n" NOR        
         NOR,me);
         message("world:world1:vision",
          HIG"\n\t�i���������j"HIW+me->name(1)+"���\\�a�V�ѯ���D��@�����H�Ͱʪ������F�I�I\n\n"+NOR
        ,users());
        
        me->add("popularity",-cost);

        //log
        log_file("static/EXCHANGE_DOLL",
                sprintf("%s(%s) exp %d at  %s\n",
                me->name(1), geteuid(me),me->query("popularity"),ctime(time()) ) );
        return 1;
}
 
int help(object me)
{
        write(@HELP
���O�榡 : exchange
 
�o�ӫ��O�i�H���A��O�n��V�^�i�ʹ����ѯ��洫�@�Ӵ��������C

�U�ر��n��n�D�p�U�G

�H���G350�I     �P���G500�I
���]�G500�I     �~�H�G600�I
��H�G600�I     ���Z�G600�I

HELP
);

    return 1;
}


