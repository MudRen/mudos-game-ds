// sacrifice
#include <ansi.h>
inherit F_FINANCE;
inherit F_VENDOR;
inherit F_CLEAN_UP;
int do_sac(object me,object ob,int world);
void create() { seteuid(getuid()); }
int main(object me, string str)
{
        object ob,*obs;
        int j,k,time;
        string name;
        if(!str) return notify_fail("�A�n�^�m����F�赹�ѯ�?\n");
        time = me->money_type();
        if(str == "all")
        {
          obs = all_inventory(environment(me));
          k=sizeof(obs);
          if( k > 0)
          {
                if( k > 10 ) k=10;
                
                for(j=0; j<k; j++)
                {
                        //if( obs[j]->is_character() ) continue;
                        if(!obs[j]) continue;
                        if(obs[j]->query("money_id")) continue;
                        if(living(obs[j])) continue;
                        if(obs[j]->is_corpse() && obs[j]->query("owner_id")) continue;
                        if(obs[j]->query("no_sac") || obs[j]->query("no_get") || obs[j]->query("no_get") ) continue;
                        do_sac(me,obs[j],time);
                }
          }
          return 1;
        }
        
        ob=present(str,environment(me));
        if(!ob) return notify_fail("�o�Ӧa��èS���o�����~�C\n");
        if(ob==me)
        {
                message_vision("$N�Q�N�ۤv�^�m���ѯ��A���O�n���S�H�z�B�C\n",me);
                return 1;
        }
        name=ob->name();
        if(ob->query("money_id")) return notify_fail("�ѯ��O�������������C\n");
        if(ob->is_corpse() && stringp(ob->query("owner_id")))
                return notify_fail("�A����^�m���a�����鵹�ѯ��C\n");
        if(ob->query("no_sac") || ob->query("no_get") || ob->query("board_id") )
                return notify_fail("�o��"+name+"�L�k�^�m�C\n");
        if(living(ob)) return notify_fail("���D"+name+"���F�A�_�h�O�Q!\n");
        if(ob->query("equipped")) return notify_fail("�A���ݥ��N"+name+"�Ѱ��˳ơC\n");
        
        return do_sac(me,ob,time);
}

int do_sac(object me,object ob,int world)
{
        object *inv;
        int money,i;
        string obname;
        money = ob->query("value")/10;
        if(money < 1 ) money = 1;

        obname=ob->short();

        message_vision("$N�N"+obname+"�^�m���j�a�C\n",me);
        me->add("bank/past", money);            
        write("�A�o��" + price_string(money, me->money_type())+"�@������C\n");

        if(ob->query_max_encumbrance()) //for corpse
        {
                inv = all_inventory(ob);
                for(i=0; i<sizeof(inv); i++)
                {
                        if(!inv[i]) continue;
                        if(inv[i]->query("equipped")) inv[i]->unequip();
                        if( !inv[i]->query("no_drop") && !inv[i]->query("no_put") ) inv[i]->move(environment(ob));
                }
        }
        
        destruct(ob);
        return 1;
}

int help(object me)
{
        write(@HELP
���O�榡: sac <item>

��A���L�h�Τ��ݭn�����~�A�i�H�N���^�m���ѯ��C
�A�i�H��o�^�m�����Ȫ�10%�A�������y�C

HELP
);
        return 1;
}

