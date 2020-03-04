#include <ansi.h>
inherit ITEM;

string *all_oppmobs = ({
"/open/world1/tmr/ghost-forest/npc/ghostking","/open/world1/tmr/area/npc/dragon","/open/world1/wilfred/meadow/npc/npc2",
"/open/world1/tmr/bagi/npc/advmaster","/open/world1/tmr/bagi/npc/cmoon","/open/world1/tmr/area/npc/master",
"/open/world1/wilfred/sand/npc/npc35","/open/world1/acme/bonze/npc/master","/open/world1/tmr/advbonze/npc/bonze_adv_master",
"/open/world1/tmr/freezetaoism/npc/tian-demon","/open/world1/acme/area/npc/liu","/open/world1/acme/areanpc/advmaster",
"/open/world1/ksj/thief/npc/thief-master","/open/world1/moonhide/area/goo.c",
"/open/world1/moonhide/area/dragongirl","/open/world1/moonhide/area/god-prey.c","/open/world1/moonhide/area/under/npc/evil"
"/open/world1/tmr/advthief/thief_adv_master.c","/open/world1/cominging/area/npc/master","/open/world1/cominging/area/npc/yuanlieh",
"/open/world1/cominging/area/npc/left-escort","/open/world1/faceoff/sky/npc/monk","/open/world1/faceoff/sky/npc/star_old_man",
"/open/world1/faceoff/sky/npc/cw_taoist","/open/world1/ksj/east_island/npc/hoshiakari","/open/world1/ksj/east_island/npc/black-tengu",
"/open/world1/ksj/east_island/npc/cat-oldwoman","/open/world1/ksj/east_island/npc/orochi-black-head","/open/world1/ksj/east_island/npc/orochi-blue-head",
"/open/world1/ksj/east_island/npc/orochi-gold-head","/open/world1/ksj/east_island/npc/orochi-green-head","/open/world1/ksj/east_island/npc/orochi-grey-head",
"/open/world1/ksj/east_island/npc/orochi-purple-head","/open/world1/ksj/east_island/npc/orochi-red-head","/open/world1/ksj/east_island/npc/orochi-white-head",
"/open/world1/ksj/lost_island/npc/blood-eye-dragon","/open/world1/ksj/lost_island/npc/sword-tiger","/open/world1/ksj/lost_island/npc/leviathan",
"/open/world1/kkeenn/love/npc/master_2","/open/world1/kkeenn/love/npc/master_1","/open/world1/kkeenn/love/npc/ron", 
"/open/world1/alickyuen/phoenix/phoenix.c"});
void create()
        {
         set_weight(5);
         set_name("[0;4;5;36m�[4;5mn[4;5m�[4;5m�[0;1;4;5;37m�[1;4;5m�[1;4;5m�[1;4;5m�[0m"NOR,({"naikum-destroy book","book"}));

         set("value", 1);
         set("long", "�@�̤��ԡA�ѥ֤W���G���ǦǹСA�����O�_�i����(clean)�@�U�H\n");
         set("unit", "��");
         setup();
}

void init()
{
        add_action("do_clean","clean");
}

int do_clean(string arg)
{
  object me = this_player();
  object ob,env;

        if(! env = environment(me)) return 0;
        if( !env->query("outdoors") )
                return notify_fail(HIW"��M���ѤO�q���A�L�q�U��C\n"NOR);
        if(!arg||arg!="book") return notify_fail("���O���~�A�ЦA��J�@��!!\n");
        switch (random(2) ){ 

                case 0:
       message_vision("$N�����F�ѤW���ǹСA���@�L�ܤơI�I\n", me);
                       me->start_busy(2); 
                       destruct(this_object());
                      break;
               case 1:
          ob= new(all_oppmobs[random(sizeof(all_oppmobs))]); 
          message("world:world1:vision",
        HIY"\n\t\t�����������M�����@�{�A���G���Ǥ����R�C\n\n"NOR
        ,users() );
          message_vision(HIG"$N"HIW"�����F�ѤW���ǹЫ�A�ðΦb�Ѥ��̪�"NOR"$n"HIW"�Ǧ����|«�k�ӥX�I�I\n"NOR, me, ob);
          ob->move(environment(me));
          ob->set("attitude", "aggressive");
          ob->kill_ob(me); 
          break;          }
          destruct(this_object());
          return 1; 
}

