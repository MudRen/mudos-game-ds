#include <ansi.h>
inherit ITEM;

void create()
{

        set_name(HIW"�ֳU"NOR,({"lucky bag","bag"}));
        set_weight(80);
        set("long","�@�ӺֳU�A�A�û������D�̭��|������E�A�i�H���}(reopen)���E\n");
        set("unit","��");
        set("value","0"); 
        setup();
}

void init()
{
        add_action("do_open","reopen");
}

int do_open(string arg) 
{
        int coco;
        object ob,ob1,ob2,me;
string eq,*eqs,eq2,*eqs2,eq3,*eqs3;
eqs  = ({
"/open/world1/ksj/east_island/npc/eq/orochi-armor-save",
"/open/world1/ksj/east_island/npc/eq/orochi-armor2-save",
"/open/world1/ksj/east_island/npc/eq/orochi-cloak-save",
"/open/world1/ksj/east_island/npc/eq/orochi-gloves-save",
"/open/world1/ksj/east_island/npc/eq/orochi-leggings-save",
"/open/world1/ksj/east_island/npc/eq/orochi-mask-save",
"/open/world1/ksj/east_island/npc/eq/orochi-shield-save",
"/open/world1/ksj/east_island/npc/eq/orochi-waist-save",
"/open/world1/ksj/lost_island/npc/eq/apollo-armor",
"/open/world1/jangshow/mage-gloves",
"/open/world1/jangshow/mage-hat",
"/open/world1/jangshow/min/sword",
"/open/world1/ksj/lost_island/npc/eq/tiger-blade",
"/open/world1/ksj/lost_island/npc/eq/tiger-claw",
"/open/world1/ksj/lost_island/npc/eq/tiger-dagger",
"/open/world1/ksj/lost_island/npc/eq/tiger-staff",
"/open/world1/ksj/lost_island/npc/eq/tiger-sword",
"/open/world1/ksj/lost_island/npc/eq/tiger-whip",
"/open/world1/ksj/lost_island/npc/eq/blood-eye-dragon-armor",
"/open/world1/ksj/lost_island/npc/eq/leviathan-earring",
"/open/world1/ksj/east_island/npc/eq/devil-cat-mask",
"/open/world1/npc/orocho-eq",
"/u/c/coffee/game/newyear/light-hands",
"/open/always/game_gift/mask",
"/open/always/game_gift/necklace",
"/open/always/game_gift/skirt",
          });

eq = eqs[random(sizeof(eqs))];   
eqs2  = ({
"/open/world1/eq/b_pants",
"/open/world1/eq/clothes_8",
"/open/world1/wilfred/sand/npc/eq/eq16",
"/open/world1/wilfred/sand/npc/eq/eq17",
"/open/world1/wilfred/sand/npc/eq/eq18",
          });
eq2 = eqs2[random(sizeof(eqs2))];   

eqs3  = ({
"/open/world1/acme/area2/npc/obj/book",

"/open/world1/acme/area2/npc/wp/ghostpike",
"/open/world1/cominging/area/npc/wp/oldsword",
"/open/world1/faceoff/sky/npc/eq/star_necklace",
"/open/world1/moonhide/pool/npc/obj/purple-sword",
"/open/world1/sdo/nonhero/obj/npc/wp/hero_pike",
"/open/world1/tmr/area/npc/wp/dab-aqua-claw",
"/open/world1/tmr/area/npc/eq/dab-aqua-armor",
"/open/world1/tmr/area/npc/wp/masterfork",
"/open/world1/wp/ds_staff",
"/open/world1/tmr/bagi/npc/eq/wu_gloves",
"/open/world1/cominging/area/sword",
"/open/world1/alickyuen/wind/only",
"/open/world1/faceoff/sky/npc/eq/world_staff",
"/open/world1/wilfred/sand/npc/eq/eq3",
"/open/world1/moonhide/pool/npc/obj/snake-waist",
"/open/world1/cominging/area/npc/wp/shangsword",
"/open/world1/acme/bonze/npc/wp/force-shake-staff",
"/open/world1/moonhide/area/sword3",
"/open/world1/acme/area/npc/wp/sunsword",
"/open/world1/acme/area/npc/wp/godsword",
"/open/world1/ksj/east_island/npc/eq/hide-bone-katana",
"/open/world1/ksj/east_island/npc/eq/kiku-ichimonji-katana",
"/open/world1/ksj/east_island/npc/eq/sakura-ranbu-katana",
"/open/world1/ksj/east_island/npc/eq/shouugan-katana",
"/open/world1/ksj/east_island/npc/eq/bizen-chousen-katana",
"/open/world1/moonhide/pool/npc/obj/soul-claw",
"/open/world1/moonhide/pool/npc/obj/mie-blade",
"/open/world1/moonhide/area/under/npc/obj/evil-spear",
"/open/world1/linjack/emperor/npc/wp/blade3",
"/open/world1/ksj/east_island/npc/eq/kusanagi-sword",
"/open/world1/moonhide/area/under/npc/obj/evil-armor-only",
"/open/world1/wilfred/sand/npc/eq/eq22",
"/open/world1/wilfred/sand/npc/wp/wp10",
"/u/f/faceoff/area/sky/eq/baal_leg",
"/open/world1/cominging/area/npc/wp/sevenstar",
"/open/world1/moonhide/pool/npc/obj/purple-bow",
"/open/world1/acme/area2/npc/eq/ghostcloak",
"/open/world1/moonhide/pool/npc/obj/purple-sword",
"/open/world1/moonhide/pool/npc/obj/turtle-armor",
"/open/world1/moonhide/area/sword",
"/open/world1/kkeenn/love/npc/obj/blood_whip",
"/open/world1/kkeenn/love/npc/obj/dragon_whip",
"/open/world1/kkeenn/love/npc/obj/ghost_whip",
"/open/world1/linjack/emperor/npc/eq/leggings",
"/open/world1/whoami/birdarea/npc/eq/dagger3",
"/open/world1/whoami/birdarea/npc/eq/fist2",
"/open/world1/whoami/birdarea/npc/eq/tooth",
"/open/world1/wilfred/sand/npc/eq/eq6",
          });
eq3 = eqs3[random(sizeof(eqs3))];  


        me = this_player();
        if (!arg || arg =="")
        return notify_fail("�A�n���}����H\n"); 
        if( me->is_busy() )
        return notify_fail("�A�٦b���I\n");
        if (arg != "bag" && arg != "lucky bag") return 0;

        switch( random(750) ){
        default: 
         coco = 8000+random(15000);        
         message_vision
("\n$N�����Ϋݪ��N$n���}�@�ݡA���G�̭��~�M�O�@�ǥj���E\n",me,this_object());
         tell_object(me,"(�t�ΡG�z��"HIC+coco+NOR"���۰ʶפJ�z���b��)\n");         
         me->add("bank/past",coco);
         break;
         case 400..405:
         ob1 = new(eq);
         message_vision
("\n$N�����Ϋݪ��N$n���}�@�ݡA���G�̭��~�M�O�@"+ob1->query("unit")+ob1->query("name")+"�E\n",me,this_object());
         ob1->move(this_player()); 
         break;
        case 1..150:
         ob1 = new(eq2);
         message_vision("\n$N�����Ϋݪ��N$n���}�@�ݡA���G�̭��~�M�O�@"
         +ob1->query("unit")+ob1->query("name")+"�E\n",me,this_object());
         ob1->move(this_player()); 
         break;
        case 501..510:
         ob1 = new("/open/always/doll");
         message_vision("\n$N�����Ϋݪ��N$n���}�@�ݡA���G�̭��~�M�O�@"
         +ob1->query("unit")+ob1->query("name")+"�E\n",me,this_object());
         ob1->move(this_player()); 
         break;  
        case 511..520:
         ob1 = new("/u/w/whoami/scroll");
         message_vision("\n$N�����Ϋݪ��N$n���}�@�ݡA���G�̭��~�M�O�@"
         +ob1->query("unit")+ob1->query("name")+"�E\n",me,this_object());
         ob1->move(this_player()); 
         break;  
        case 650..749:
         ob1 = new(eq3);
         message_vision("\n$N�����Ϋݪ��N$n���}�@�ݡA���G�̭��~�M�O�@"
         +ob1->query("unit")+ob1->query("name")+"�E\n",me,this_object());
         ob1->move(this_player()); 
         break;
        }

        destruct(this_object());
     
  return 1;

}

