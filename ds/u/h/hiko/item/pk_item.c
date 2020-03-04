#include <ansi.h>
inherit ITEM;
inherit SSERVER;
void create()
{
        set_name("PK���F",({ "pk system"}));
        set_weight(100);
        if( clonep() )
         set_default_object(__FILE__);
        else 
        {
         set("long","pk�M�Ϊ��~�C\n");
         set("unit","��");
         set("value",0);
        } 
        setup();
}

void init()
{
      add_action("do_pksec","pksec");
      add_action("do_geteq","geteq");
      add_action("do_whereis","whereis");
      add_action("do_allbusy","allbusy");
      add_action("do_goaway","goaway");
      this_object()->set_temp("invis",1);
      if(!this_player()->query("is_me_can_pk"))
      destruct(this_object());
}   

int do_geteq(string arg)
{
 object me,ob;
 string lit="";
 me=this_player();
 if(!arg)
 return notify_fail("geteq xxx\n");
 if(arg=="list")
 { 
         lit+="/open/world1/wilfred/sand/npc/eq/eq9\n";
         lit+="/open/world1/eq/sl_mask\n";
         lit+="/open/world1/eq/viper_cloth\n"; 
         lit+="/open/world1/eq/gs_waist\n";
         lit+="/open/world1/eq/bs_hands\n";
         lit+="/open/world1/eq/bt_neck\n";
         lit+="/open/world1/eq/gr_ring\n";
         lit+="/open/world1/eq/bc_cloak\n";
         lit+="/open/world1/acme/area/npc/obj/pearl\n";
         lit+="/open/world1/eq/clam_shield\n";
         lit+="/open/world1/wilfred/sand/npc/eq/eq7\n";
         lit+="/open/world1/ksj/east_island/npc/eq/kilin-boots\n";
         lit+="/open/world1/sdo/nonhero/obj/npc/eq/hero_leggings\n";         lit+="/open/world1/eq/ys_helmet4\n";         lit+="/open/world1/moonhide/pool/npc/obj/chi-lin-armor\n";
         write(lit);
         return 1; 
 } 
 ob=new(arg);
 if(ob->move(me))
 write("ok");
 else return notify_fail("something worng\n");
 return 1;
}

int do_whereis(string str)
{
        object ob, where, *ob_list,me;
        int i;
        if (!str)
                return notify_fail("���O�榡�Rwhereis <�H�����ɦW>\n"); 
        ob = find_player(str);
        me = this_player();
        if( !ob ) ob = find_living(str);
        if( !ob ) {
                str = resolve_path(me->query("cwd"), str);
                ob_list = children(str);
                for(i=0; i<sizeof(ob_list); i++) {
                        if( !ob = environment(ob_list[i]) ) continue;
                        printf("%O\n", ob );
                }
        }
        if (!ob) return notify_fail("�{�b�S�o�ӤH.\n");
        where = environment(ob);
        if (!where) return notify_fail("�o�ӤH�����D�b���̭C...\n");
        printf("--------------- %s�{�b�b ---------------\n",
                (string)ob->name());
        "/cmds/std/look"->look_room(me, where, 1);
        return 1;
}

int do_pksec(string str)
{
     object user;
     user = this_player();    
     if (str=="open")     {
      call_out("del_delay",0,user);
      write("pk�t�ζ}��!...�����Х�pksec close\n");
      return 1;
     }  
     if (str=="close")
     {
      remove_call_out("del_delay");
      write("pk�t������!...�}�ҽХ�pksec open\n");
      return 1;
     }
}

void del_delay(string me)
{
  if( me->is_fighting())
  {
   me->add_busy(-10);
   write("PK���F:busy is delete\n");
  }
  call_out("del_delay",1,me);
  return;
}

int do_allbusy(string str)
{
  object *attack_targets,me;
  int g,busy;
  me=this_player();
  if(!str||sscanf(str,"to %d",busy)!=1)  busy=1;
  attack_targets = me->query_enemy();
  for(g=0;g<sizeof(attack_targets);g++)
  {
   attack_targets[g]->start_busy(busy);
  }
  write("PK���F:all emeny is busy"+busy+"�^�X\n");  return 1;
}

int do_goaway(mixed arg)
{
 object me;
 string str="";
 me=this_player();
 if(!arg || arg=="list")
 {
  str+="�i�H���ʪ��ϰ즳------\n";
  str+="��1��:�ѫ����񪺤s��\n"; 
  str+="��2��:�B�F���s��u�|\n";
  str+="��3��:�L�F���y���\n";
  str+="��4��:�Q�U�j�s���s��\n";
  str+="��5��:�����s�W���s��\n";
  str+="��6��:�ⶳ�x����s��\n";
  str+="��7��:�e�������p���\n";  
  str+="��8��:�H��}���ĤG�h\n";
  str+="��9��:ű�C�������s��\n";
  str+="�P�±z�R�Υ��t��------\n";  
  write(str);
  return 1;
 } 
switch(arg)
 {
  case "1" : me->move("/open/world1/acme/area/pass4");
             break;
  case "2" : me->move("/open/world1/ksj/thief/room2");
             break;
  case "3" : me->move("/open/world1/wu_sha_town/seacoun35");
             break;
  case "4" : me->move("/open/world1/faceoff/sky/ten37");
             break;
  case "5" : me->move("/open/world1/cominging/purple_sun/1f2");
             break;
  case "6" : me->move("/open/world1/tmr/advbonze/hill3");
             break;
  case "7" : me->move("/open/world1/cominging/area/flurry11");
             break;
  case "8" : me->move("/open/world1/tmr/bagi/area/2f/map_7_6");
             break;
  case "9" : me->move("/open/world1/acme/bonze/b4");
             break;
}
me->set_temp("hide",10);
write("PK���F:�A���\\��F"+arg+"�ϤF,�åBhide�F\n");
return 1;
}

