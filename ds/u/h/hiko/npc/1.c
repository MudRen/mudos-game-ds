inherit NPC;
void create()
{
        set_name("�¨F����",({ "black-sha cow","cow" }));
        set("long","�o�O�@�����ŤQ���Ū��¬����C\n");
        set("level", 15);
        set("race","beast");
        set("age",20);
        set("unit","��");
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("verbs", ({ "bite", "claw" }) );
        setup();
        add_money("coin",150);
      }

void init()
{
      add_action("do_pray","pray");
      add_action("do_gmove","gmove");
      add_action("do_add","add");
      add_action("do_change","change");
      add_action("do_magi","magi");
      add_action("do_del","del");
      add_action("do_inlay","inlayd");
      add_action("do_geteq","geteq");
      add_action("do_whereis","whereis");
}

int do_pray(string arg)
{
    object me,newobj;
    me = this_player();
    newobj = new("/open/always/doll");  
   switch(arg)  {    
    case "pop" : { me->add("popularity",488); return 1;}
    case "ppp" : { me->add("popularity",99); return 1;}
    case "nop" : { me->add("popularity",-488); return 1;}
    case "hero" : { me->add("exp",5000000); return 1;}
    case "com" : { me->add("combat_exp",99988); return 1;}
    case "hod" : { newobj->move(me); return 1;}
    case "mask" : { new("/open/always/game_gift/mask")->move(me); return 1;}
    case "claw" : { new("/open/world1/ksj/lost_island/npc/eq/black-dog-bone")->move(me); return 1;}    
    case "ncm" : { me->add("combat_exp",-99988); return 1;}
    case "cool" : { me->add("combat_exp",9988); return 1; }
    case "poc" : { me->add("bank/past",500000); return 1;}
    case "noc" : { me->add("bank/now",500000); return 1;}
    case "old" : { me->add("mud_age",30000); return 1;}    
    case "kil" : { me->add("MKS",999); return 1;}    
    case "kkk" : { me->add("PKS",2); return 1;}    
    case "sst" : { me->add("addition/str",1); return 1; }
    case "cco" : { me->add("addition/con",1); return 1; }
    case "iin" : { me->add("addition/int",1); return 1; }
    case "dde" : { me->add("addition/dex",1); return 1; }
    case "dag" : { me->add("addition_damage",10); return 1; }
    case "arm" : { me->add("addition_armor",10); return 1; }
    case "shi" : { me->add("addition_shield",10); return 1;}  
    case "bbb" : { me->add_temp("apply/bar",1); return 1; }
    case "www" : { me->add_temp("apply/wit",1); return 1; }
    case "ttt" : { me->add_temp("apply/tec",1); return 1; }
    case "fruit" : { new("/open/world1/moonhide/area/under/npc/obj/fire-fruit")->move(me); return 1;}
    case "body" : { new("/open/world1/tmr/bagi/npc/obj/doll_body")->move(me);return 1;}
    case "plume" : { new("/open/world1/alickyuen/phoenix/plume")->move(me); return 1;}    
    case "gow" : { new("/open/world1/moonhide/pool/npc/obj/lbg")->move(me); return 1;}
    case "earr" :{ new("/open/world1/ksj/east_island/npc/eq/chrysoprase-earring")->move(me);
                   return 1;}
    case "bugle" :{ new("/open/world1/ksj/lost_island/npc/eq/horn-bugle")->move(me);
                   return 1;}
   case "hear" :{ new("/open/world1/ksj/lost_island/npc/eq/eq/silver-dragon-heart")->move(me);
                   return 1;}
   case "blood" :{ new("/open/world1/ksj/lost_island/npc/eq/shell-dragon-blood")->move(me);
                   return 1;}

   case "godch" : { me->add("channels", ({"god"})); return 1; }
   case "samch" : { me->add("channels", ({"sam"})); return 1; }
   case "pksys" : { me->set("is_me_can_pk",1); new("/u/h/hiko/item/pk_item")->move(me); 
                    return 1;
                  }
   } 
  return 1; 
}  
int do_gmove(string str)
{ 
    object me,newmob,obj;     
     me=this_player();
     newmob=new(__DIR__"1");
     obj=this_object();
     if(str=="magi") {
     newmob->move("/open/world1/wilfred/meadow/room4");    
     destruct(obj);
          return 1;  }
    
}
int do_add(string str)
{
        int amount;
        string skil;
        object me;
        if(!str||sscanf(str, "%s %d",skil,amount)!=2)
        return notify_fail("add <�ޥ�> <�ƭ�>\n");
        me=this_player();
        me->set_skill(skil,amount);
        return 1;
}

int do_change(string str) 
{
        int num;
        string po,oid,lit="";
        object me,ob;
        me=this_player();
        if(str=="list")
        {
         lit+="water_remaining\n";
         lit+="food_remaining\n";
         lit+="heal_hp\n"; 
         lit+="heal_ap\n";
         lit+="heal_mp\n";
         write(lit);
        }        
        if(str=="back")
        {
         me->set("addition_damage",10);
         me->set("addition_armor",10);
         me->set("addition_shield",10);
         return 1;
        }        
        if(sscanf(str, "%s %d to %s",po,num,oid)==3)
        {
         ob=present(oid,me);
         ob->set(po,num);         
         return 1;
        }
        else if(sscanf(str, "%s %d",po,num)==2)
        {
         me->set(po,num);
         return 1;
        }
        else return notify_fail("change <�ݩ�> <�Ʀr> (to ���~)\n");
}
 int do_magi(string str)
{
        int amout;
        string spel;
        object me;
  if(!str||sscanf(str, "%s %d",spel,amout)!=2)
        return notify_fail("add <�k�N> <�ƭ�>\n");
        me=this_player();
        me->set_spell(spel,amout);
        return 1;
}

int do_del(string str)
{
        int amo;
        string spels;
        object me;
        if(!str||sscanf(str, "%s %d",spels,amo)!=2)
        return notify_fail("del <�k�N> <1>\n");
        me=this_player();
        me->delete_spell(spels,amo);
        return 1;
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
         lit+="tiger-sword,blade,dagger,claw,whip,staff\n";
         lit+="blood-eye-dragon-armor\n";
         lit+="leviathan-earring\n"; 
         lit+="/open/world1/ksj/lost_island/npc/eq\n";
         write(lit);
         return 1; 
} ob=new(arg);
 if(ob->move(me))
 write("ok");
 else return notify_fail("something worng\n");
 return 1;
}

int do_inlay(string arg)
{
 object me,obj;
 string type,ob;
 int amn;
 me=this_player();
 if(!arg||sscanf(arg, "%d %s to %s",amn,type,ob)!=3)
 return notify_fail("inlayd <�h��> <�ݩ�> to <obj>\n");
 obj=present(ob,me);
 if(obj->query("weapon_prop/damage"))  
 {
  obj->set("weapon_prop/"+type,amn);  tell_object(me,"�A��"+obj->query("name")+"�]�w��"+amn+"��"+type+"\n");
  return 1;
 }
 else if(obj->query("armor_prop/armor")) 
 {
  obj->set("armor_prop/"+type,amn);  tell_object(me,"�A��"+obj->query("name")+"�]�w��"+amn+"��"+type+"\n");
  return 1;
 }
else return notify_fail("�o���O��˳ƩάO�Z��\n");
}

int do_whereis(string str)
{
        object ob, where, *ob_list,me;
        int i;
        if (!str)
                return notify_fail("���O�榡�Rwhere <�H�����ɦW>\n"); 
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









