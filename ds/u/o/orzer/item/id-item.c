//�g�n����...
inherit ITEM;
#include <ansi.h>
void create()
{
    set_name("���F��",({"gilin stone","stone"}));
    set("long","�ӸO�A�൹�Y�H(givename)��r��C\n");
    set("unit","��");
    set("value",99999);
    set("no_get",1);
    set("no_sac",1);
    setup();
}
void init()
{
        add_action("do_ids","ids");
} 
  

int do_ids(string arg)
{
        int i, j;
        object obj, *inv,me=this_player(),who;
        string *id,str,tar,obs;

        if( !arg ) {
                inv = all_inventory(me);
                if( !sizeof(inv) )
                        return notify_fail("�A���W�S������F��C\n");
        write( "�A(�p)���W��a���~���O�٦p�U(�k��) :\n");
                for(i=0; i<sizeof(inv); i++) {
                        if( !me->visible(inv[i]) ) continue;
                        if(inv[i]->query("secured")) str=" (�O�@��)"; else str="";
                        printf("%-20s = %s\n", inv[i]->name()+str,
                                implode(inv[i]->parse_command_id_list(), ", ") );
                }
                return 1;
        }
    
        if(sscanf( arg,"%s %s",tar,obs)==2)
        {
          who=find_living(tar);
          if(who) obj=present(obs,who);
        }
        else if(arg!="here")
              obj=present(arg,environment(me));
        else obj=environment(me);
        if(obj) {   
                inv = all_inventory(obj);
                if( !sizeof(inv) )
                        return notify_fail("�o�̨S������F��C\n");
                write( "�b"+obj->name()+", �ͪ��Ϊ��~��(�^��)�W�٦p�U :\n");
                        for(i=0; i<sizeof(inv); i++)
                        {
                                if(!me->visible(inv[i]) ) continue;
                                printf("%-20s = %s (�ɮ�:%s.c)\n", inv[i]->name(),
                                implode(inv[i]->parse_command_id_list(), ", "),base_name(inv[i]));
                        }
                        return 1;
        }
         else return notify_fail("�S���o�ӪF��C\n");
}


