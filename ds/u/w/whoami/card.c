#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIC"�P��d��"NOR, ({ "let's go card","card" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�i");
                set("long", "\n");
                set("value",0);
               }
        setup();
}

void init()
{
        add_action("do_move","move");
}

int do_move(string arg)
{
        object me,place,player,*obs;
        me = this_player();
        if( !arg )
          return notify_fail("�Ϊk: move �H(�Ωж�)\n");
        if( player = find_player(arg) && player = find_living(arg) ){
        message_vision(HIC"�ϥΦP��I"HIY+player->query("name")+"�I\n",me);
        obs = all_inventory(environment(me));
        for(int x=0; x<sizeof(obs);x++) {
                if( !userp(obs[x]) || !living(obs[x]))continue;
                message_vision(HIW"\n�u��$N�����γQ�@�}���~�]���A�K�����b�Ů𤧤��E\n"NOR,obs[x]);
                obs[x]->move(environment(player));
                }  
        } else if( file_size(arg)>0 ) {  
        place = load_object(arg);
        message_vision(HIC"�ϥΦP��I"NOR"�e��"HIY+place->query("short")+"�I\n",me);
        obs = all_inventory(environment(me));
        for(int x=0; x<sizeof(obs);x++) {
                if( !userp(obs[x]) || !living(obs[x]))continue;
                message_vision(HIW"\n�u��$N�����γQ�@�}���~�]���A�K�����b�Ů𤧤��E\n"NOR,obs[x]);
                obs[x]->move(place); 
                }        } else {
        tell_object(me,"�S���o�Ӫ��a�Φa��C\n");  
        }
        return 1;
}

