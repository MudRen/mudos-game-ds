inherit ROOM;
#include <ansi.h>
#include <room.h>

void create()
{
set("short", HIC"�Ϣ���"HIW"�u�@��"NOR);
  set("long",
"�o���u�@�Ǩѵ����Ǧ�"HIR"���D"NOR"�Q"HIC"��"HIW"�Ϣ���"NOR"���H�@�ӥi�H�o�ݪ��a��
�A���ެO������D�A�u�n"HIW"�Ϣ���"NOR"�|���A�L���|�ɤO�^���A���L�L�̪�
��b�Ӧ��F�A�p�G���D�@���o����^���A"HIM"�Э@�ߵ���"NOR"�a�C"HIG"��������B
�Ϣ��@�Ϣ������\n\n"NOR);
set("exits", ([
"wiz" : "d/wiz/hall1",
  "mulder" : "/u/m/mulder/workroom.c",
  "mail" : "/open/world1/tmr/area/post_office",
 ]));
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 setup();
call_other("/obj/board/aoe_b", "?!?!");
}
void init()
{
        object me;
        seteuid(getuid());
        me = this_player();
        if (me)
        add_action("do_qwiz","qwiz");
}

int do_qwiz(string arg)
{
        int i,j=0,n,idle;
        object *user_list,where;
        string status1, status2, status3;

        user_list = users();
        n = sizeof(user_list);
        write(HIY"YELLOW LCD"NOR"�{�{�ۡA���˾����b��M��Lwiz....\n");
        for( i=0 ;i<n ;i++)
        {
                if( wizardp(user_list[i]))
                {
                        where = environment(user_list[i]);
                        idle=query_idle(user_list[i]);
                        if (in_input(user_list[i])) status1=HIY"(INPUT)"NOR;
                                else status1="";
                        if ((in_edit(user_list[i])))
        status2=sprintf(HIY"(EDIT: %s)"NOR,in_edit(user_list[i]));
                                else status2="";
                        if (idle>180) status3=sprintf(HIY"(IDLE %d MIN)"NOR,idle/60);
                                else status3="";
                        write(sprintf("TTF [ %2d %12s %s(%s) ���b %s(%s) ]\n",
                        j,
                        SECURITY_D->get_status(user_list[i]),
                        user_list[i]->query("name"),
                        user_list[i]->query("id"),
                        (string)where->query("short"),
                        (string)file_name(where)));
                        if ((status1!="")||(status2!="")||(status3!=""))
                        write(sprintf("TTF [                STATUS: %s%s%s]\n",
                                      status1,status2,status3));
                        j++;
                }
        }
        return 1;
}
/*
// �i�H�ΨӰ��S��ĪG(�p�S��,���,���r,�ɦ�,�άO�w�ɰT��)
int room_effect(object me)
{
        switch(random(14))
        {
                
         case 7:        message_vision("���p����z�a!!�@$N��M�Q�@�����L���ߧ�F�X�U�C\n",me);
                        me->receive_damage("hp",random(3)+1);
                        return 1;
         case 6:        message_vision("�㫦���ݢ�Ѣ�!!�@$N��M�Q�@��ī�G�{���Y�C\n",me);
                        me->receive_damage("mp",random(3)+1);
                        return 1;
         case 5:
         case 4:        tell_object(me,"�㫦���@���߬�M���b�L�h�C\n");
                        return 1;
         
         case 3:
         case 2:        tell_object(me,"�㫦���@��ī�G�q���᪺ī�G�𱼤U�ӡC\n");
                        return 1;
         case 1:
         case 0:        message_vision("$N�}�l�������o�_�b�ӡC\n",me);
                        return 1;
   
         default:       return 1;
        }
}
*/
