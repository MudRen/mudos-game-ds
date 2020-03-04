// 2001.8.19 Com@DS �ק�
#define DROP_CMD "/cmds/std/drop"
#include <ansi.h>
inherit F_DBASE;
inherit F_CLEAN_UP;

void create() 
{
        seteuid(getuid());
        set("channel_id", "���u���F(Kickout)");
}

int main(object me, string arg)
{
        int i;
        object ob, *team, ride;
          object *inv;
                        
        if( !arg ) return notify_fail("���O���: kickout <id>\n");       
        ob = find_player(arg); //present(arg, environment(me));
        if( !ob ) return notify_fail("�S���o�ӤH\n");
        if(  wiz_level(me) <= wiz_level(ob) ) 
                 return notify_fail("�A�S���o���v�O�C\n");
// add ++
        if(team=ob->query_team())
        {
                if(arrayp(team) && sizeof(team)>1 )
                {
                        for(i=0;i<sizeof(team);i++)
                        {
                                tell_object(team[i],HIW"�i����j"+ob->name(1)+"���}�F�o�Ӷ���C\n"+NOR);
                                ob->dismiss_team();
                        }
                }
        }

        if( !wizardp(ob) ) {
                inv = all_inventory(ob);
                for(i=0; i<sizeof(inv); i++)
                {
                        if( inv[i]->query("secured") ) inv[i]->delete("secured");
                        if( inv[i]->query("base_value") ) continue;
                        if( inv[i]->query_autoload()  ) continue;
                        if( inv[i]->query("equipped")) inv[i]->unequip();
                        DROP_CMD->do_drop(ob, inv[i]);
                }
        }
// add --

        CHANNEL_D->do_channel(this_object(), "sys",
                me->name()+"("+"��"+")"+ob->name() + "(" + ob->query("id") + ")��X�F�C���C");
        CHANNEL_D->do_channel(this_object(), "rumor",
                ob->name() +"("+ob->query("id")+")"+ "�Q�t�ν�X�F�C���C");

// add ++
        if(ride=ob->query_temp("ride"))
        {
                message_vision("$N�q"+ride->name()+"�W���F�U�ӡC\n", ob);
                ride->delete_temp("riden");
                ride->move(environment(ob));
                ob->delete_temp("ride");
        }
        ob->remove_all_killer();
        ob->remove_all_enemy();

        ROOM_D->moveout(environment(ob),ob); //add by luky
// add --
        ob->save();
        destruct(ob);
        return 1;
}


