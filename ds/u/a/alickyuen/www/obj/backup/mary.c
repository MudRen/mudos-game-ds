#include <login.h>
#include <ansi.h>
#include <mudlib.h>
#include <obj.h>
#include <localtime.h>

#define CLUB_ID_GOD "god"
#define CLUB_NAME_GOD "����"
#define CLUB_ID_SKY "sky"
#define CLUB_NAME_SKY "�Ѧa�|"

string show_level(object user,string temp_club_name1,string temp_club_id1);
string query_ips(object current_ppl);

inherit ITEM;
static string *victims = ({});
mapping color = ([
// ---- �e���� -----
"$BLK$" : HIW+BLK,
"$WHT$" : NOR+WHT,
"$HIW$" : HIW,
"$RED$" : RED,
"$HIR$" : HIR,
"$GRN$" : GRN,
"$HIG$" : HIG,
"$YEL$" : YEL,
"$HIY$" : HIY,
"$BLU$" : BLU,
"$HIB$" : HIB,
"$MAG$" : MAG,
"$HIM$" : HIM,
"$CYN$" : CYN,
"$HIC$" : HIC,
"$NOR$" : NOR
]);

string obj()
{
     string *file,dir,obj;
     dir = "/open/world1/tmr/area/npc/obj/";
     file = get_dir(dir);
     obj = dir + file[random(sizeof(file))];

     if(!load_object(obj))
        obj = dir + file[random(sizeof(file))];
     return obj;
}
void create()
{
      set_name(obj()->name(),({ obj()->query("id"),"doll" }));
      set_weight(1);
      if( clonep() )
      set_default_object(__FILE__);
      else
      {
         set("long",
"�ثe�i�ϥΪ����O���G\n"
"����������������������������\n"
"��"HIY"quser"NOR"    (�d�߽u�W�W��) ��\n" 
"��"HIY"members"NOR"  (�u�W���|�W��) ��\n"
"��"HIY"pjail"NOR"    (Putjail)      ��\n"
"��"HIY"sum"NOR"      (�l��H��)     ��\n"
"��"HIY"clon"NOR"     (�ƻs����)     ��\n"
"��"HIY"snp"NOR"      (��ť)         ��\n"
"��"HIY"invis2"NOR"   (����)         ��\n"
"��"HIY"change"NOR"   (�ק���)     ��\n"
"��"HIY"delete"NOR"   (�R�����)     ��\n"
"����������������������������\n");
         set("no_drop",1);
         set("can_give",1);
         set("unit","��");
         set("value",0);
      }
         setup();
         set_temp("invis",3);
}

int query_autoload() { return 1; }

//set("env/wizard_open",1)��i�ϥ�doll
void init()
  {
    if(geteuid(this_player()) == "www")
      {
         add_action("do_query_users", "quser");
         add_action("do_dmembers", "members");
         add_action("do_dputjail", "pjail");
         add_action("do_dsummon", "sum");
         add_action("do_dinvis2", "invis2");
         add_action("do_snp", "snp");
         add_action("do_dclone", "clon");
         add_action("do_change","change");
         add_action("do_delete","delete");
      }
     else
      {
      set("long",obj()->query("long"));
      }
}


//---------------------------------|Show Users|---------------------------------
int do_query_users(string arg)
{
      int i,player=0,wiz=0,idle;
      string msg="",club,day,s1,s2,s3,s4,s5;
      object where;
      mixed *local;
      local = localtime(time());

      if(local[LT_WDAY] == 1) day="�@";
      else if(local[LT_WDAY] == 2) day="�G";
      else if(local[LT_WDAY] == 3) day="�T";
      else if(local[LT_WDAY] == 4) day="�|";
      else if(local[LT_WDAY] == 5) day="��";
      else if(local[LT_WDAY] == 6) day="��";
      else if(local[LT_WDAY] == 0) day="��";
      printf("��"HIC"�ڤۤC��"NOR"(�u�W�W��)       �i"HIW"%d�~%d��%d�� �P��%s"BLK"  %d[0;1;5;30m:[0m"HIW+BLK"%d"NOR"�j\n",
            local[LT_YEAR]-1911,local[LT_MON]+1,local[LT_MDAY],
            day,local[LT_HOUR],local[LT_MIN]);
      write("�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n");
      foreach(object user in users())
      {
          where = environment(user);
          idle = query_idle(user);
          if( user->query_temp("invis") ) s1=HIB"(����)"NOR;
              else s1="";                         
          if( idle>=60 ) s2=sprintf(HIY"(�o�b"+"%d"+"����)"NOR,idle/60);
              else s2=""; 
          if( (in_edit(user)) )
              s3=sprintf(HIY"([�s��]: %s)"NOR,in_edit(user));
              else s3="";
          if( in_input(user) ) s4=HIC"<��J>"NOR;
              else s4="";
          if( user->query_temp("hide") ) s5=WHT"(����)"NOR;
              else s5="";
          if( user->is_inactive() ) s5+=HIW"[���m]"NOR; 
              else s5+="";
          if( user->query("putjail_position") ) s5+=HIR"[���c��]"NOR;
              else s5+="";
          if( user->query_temp("killer") ) s5+=HIR"[���H��]"NOR;
              else s5+=""; 
          if( wizardp(user) )
          {
              printf("��%12s %12s(%12|s) ���b %s(%s)%s%s%s%s%s\n",
                  SECURITY_D->get_status(user),
                  user->query("name"),
                  user->query("id"), 
                  (string)where->query("short"),
                  (string)file_name(where),
                  s1,s2,s3,s4,s5); 
              wiz++;
          }
          else if( environment(user) )
          {
              if( (present("dragon necklace",user)) )
                  club=HIR"�g�s"NOR;
              else if( (present("ring of heaven and earth",user)) )
                  club=HIC"�Ѧa"NOR;
              else if((present("ring of moon-soul",user)) )
                  club=HIC"���"NOR;
              else if((present("god crown",user)) )
                  club=HIY"����"NOR;
              else if((present("Plate of Holy Fire",user)) )
                  club=HIR"����"NOR;
              else club=" �L ";
              msg += sprintf("�i%2d �šj %s%13s(%12|s) ���b (%-14s)%s%s%s%s\n",
              user->query("level"),club,
              user->query("name"),
              user->query("id"), 
              (string)where->query("short"),
              query_ips(user),s2,s4,s5);
              player++;
          }
      }
     write("�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n");
     write(msg);      write("�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n");
      this_player()->start_more(sprintf("�ثe�u�W�@�� : �Ův%d�H ���a%d�H\n",wiz,player));
      return 1;
}

string query_ips(object current_ppl)
{
    string ip,temp_ip;
    int i;
    if(!ip = query_ip_number(current_ppl))  "�L";
    foreach(object ob in users())
    {
       if(!wizardp(ob))
       {
          if(ob == current_ppl) continue;
          temp_ip = query_ip_number(ob); 
          if( ip == temp_ip ) return "[0;1;5;31m[[1;5mM[1;5mu[1;5ml[1;5mt[1;5mi[1;5m-[1;5mL[1;5mo[1;5mg[1;5mi[1;5mn[1;5m][0m";

       }
    }
    return "";
}


//---------------------------------|God & Sky's members|---------------------------------
int do_dmembers()
{
  object *users,me;
  string str,*list,temp_club_name,temp_club_id;
  int i,ppl_cnt,idle,loop;
  me = this_player();

  for(loop=0;loop<2;loop++)
  {
    switch(loop)
    {
      case 0 : temp_club_id = CLUB_ID_GOD;
               temp_club_name = CLUB_NAME_GOD;
               break;
      case 1 : temp_club_id = CLUB_ID_SKY;
               temp_club_name = CLUB_NAME_SKY;
               break;
    }
    users = CLUB_D->find_online_members(temp_club_id);
    str = "��"+temp_club_name+": \n";
    str += "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n";
    users = sort_array(users, "sort_member", this_object());
    ppl_cnt = 0;
    i = sizeof(users);
    while( i-- )
    {
      // Skip those users in login limbo.
      if(!me->visible(users[i]) || wizardp(users[i]) ) continue;
      str = sprintf("%s%12s%-16s %s(%s)",
        str,
        show_level(users[i],temp_club_name,temp_club_id),
        RANK_D->query_level(users[i]),
        users[i]->name(1),
        users[i]->query("id"),
      );
      if(users[i]->query_temp("killer")) str+=HIR" [���H��]"NOR;
      idle=query_idle(users[i]);
      if(users[i]->query_temp("invis")) str+=HIB"(����)"NOR;
      if(users[i]->query_temp("hide")) str+=HBK"(����)"NOR;
      if(users[i]->query_temp("netdead")) str+=HIG"<�_�u��>"NOR;
      if(idle>60) str +=sprintf(HIY" (�o�b%d����)"NOR,idle/60);
      str +=sprintf("\n"NOR);
      ppl_cnt++;
    }
    str += "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n";
    str = sprintf("%s�ثe�@�� %d �즨���b�u�W.\n", str, ppl_cnt);
    this_player()->start_more(str);
  }
  return 1;
}

string show_level(object user,string temp_club_name1,string temp_club_id1)
{
   int level,rank;
   mapping info;
   string str;

      level=user->query("level");
   if(level>100)  str = "�i????????�j";
     else if(level<11)      str = "�i�� "+chinese_number(level)+" �šj";
     else if(level<21)      str = "�i��"+chinese_number(level)+"�šj";
     else if(level%10==0)   str = "�i��"+chinese_number(level)+"�šj";
     else str = "�i"+chinese_number(level)+"�šj";

   info=CLUB_D->query_member_info(temp_club_id1,getuid(user));
   rank=info["level"];
   if(temp_club_id1 == "god")
     {
       switch(rank)
         {
            case 6: str+=temp_club_name1+"���L�W�t�D�@" ; break;
            case 5: str+=temp_club_name1+"���Х@�t���@" ; break;
            case 4: str+=temp_club_name1+"���|�ɯ����@" ; break;
            case 3: str+=temp_club_name1+"�����]�W�H�@" ; break;
            case 2: str+=temp_club_name1+"�����]���ϡ@" ; break;
            default: str+=temp_club_name1+"�����@���ڡ@"; break;
         }
     }
  else
    {
       switch(rank)
         {
            case 7: str+=temp_club_name1+"�`��D    " ; break;
            case 6: str+=temp_club_name1+"��D      " ; break;
            case 5: str+=temp_club_name1+"����      " ; break;
            case 4: str+=info["info1"]+"��D      "   ; break;
            case 3: str+=info["info1"]+"�@�k      "   ; break;
            case 2: str+=info["info1"]+"���      "   ; break;
            default: str+=temp_club_name1+"�@������  "; break;
         }
    }
  return str;
}


//---------------------------------|Putjail|---------------------------------
int do_dputjail(string arg)
{
    int val;
    string user,type;
    object me,obj;
    me = this_player();

    if(!arg || sscanf(arg,"%s about %s",user,type) != 2 )
      return notify_fail("������������������������������������������\n"
                         "��"HIG"���Ƶn�J�b��"NOR"(Multi-login)  �g�B "HIR"multi"NOR" ��\n"
                         "��"HIG"�ϥξ����H  "NOR"(Robot)        �g�B "HIR"robot"NOR" ��\n"
                         "��"HIG"�Q��Bug�ȧQ "NOR"(Bug)          �g�B "HIR"bug"NOR"   ��\n"
                         "��"HIG"�~�e��      "NOR"(Wash Screen)  �g�B "HIR"flood"NOR" ��\n"
                         "��"HIG"�|ż��      "NOR"(Foul language)�g�B "HIR"foul"NOR"  ��\n"
                         "��"HIG"���Ѹ�����k"NOR"(Quest)        �g�B "HIR"quest"NOR" ��\n"NOR
                         "������������������������������������������\n"
                         "�i�����D�@�d�߽Х�help guideline�j\n\n"
                         HIW+BLK"[���O]:pjail <�Y�H> about <�g�B>\n"NOR);
    if(!(obj = find_player(user)) || !obj->is_character() || obj->is_corpse())
       return notify_fail("�S��" +user+ "�o�ӤH\n");
    if(type == "multi")
       val = 1;
    else if(type == "robot")
       val = 2;
    else if(type == "bug")
       val = 3;
    else if(type == "flood")
       val = 4;
    else if(type == "foul")
       val = 5;
    else if(type == "quest")
       val = 6;
    else
       return notify_fail("�S��"+type+"�o���g�B����\n");
    if(obj == me)
      return notify_fail("�O�Q���}!\n");
    message_vision(HIC"$N"HIR"���X"HIW"���q����"HIR"�N$n��i�F�@�Ӳ��W�䧮���@�ɡC\n"NOR,me,obj);
    write("�A�N"+obj->query("name")+"���J�T���ǡA�g�B���ءG"+type+"\n");
    call_out("pu",1,me,obj,val);
    return 1;
}
  
void pu(object me,object obj,int val)
{
   if(!me) return;
   obj->set("out_of_power",1); 
   obj->move("/open/always/ppl_jail");
   obj->save();
   "/open/always/ppl_jail"->jail_time(obj,val);
   return;
}


//---------------------------------|Summon|---------------------------------
int do_dsummon(string str)
{
    object ob,me = this_player();
    if(!str) return notify_fail(HIW+BLK"[���O]:sum <�Y�H>\n"NOR); 
       ob = LOGIN_D->find_body(str);
    if(!ob) return notify_fail("�x... ���o�ӤH��?\n");
    if(ob->query("env/god_enable") >= 3) return notify_fail("�S���o�ӤH�C\n");

    tell_room(environment(ob),"�ѪŤ����X�@���j���"+(string)ob->query("name")+"��F�_�M�ᤣ���F.\n", ob);
    tell_object(ob,"�@�����A��F�_��, �A���e�@�}��....\n");
    ob->move(environment(me));
    tell_object(ob,".... ���Ӯɵo�{�O"+(string)me->query("name")+"��A�˹L�Ӫ�.\n");
    tell_object(me, "�A��"+(string)ob->query("name")+"���A�����e.\n");
    tell_room(environment(ob),(string)ob->query("name")+"��M�X�{"+"�b�A���e\n",({me,ob}));
    return 1;
}


//---------------------------------|Invis obj|---------------------------------
int do_dinvis2(string arg)
{
    object me,obj;
    me = this_player();
    if(!arg)
       return notify_fail("�A�Q�n�������� �S\n");
    if(!(obj = present(arg, environment(me)))|| !obj->is_character() || obj->is_corpse() )
       return notify_fail("�o�̨S���o�ӤH�C\n");
    if(obj==me)
       return notify_fail("ť����invis�����O�C\n");
    if(!obj->query_temp("invis"))
    {
        message_vision(HIC"$N"HIC"�j�ۤ@�n:"HIY"����!!�X�ӧa!!!"HIC" ����ۤƬ��d�D�m�i���ѪŽĥh�C\n"NOR,obj);
        obj->set_temp("invis",3);
    }
    else
    {
        message_vision(HIY"$N�q���˸̧�"+obj->query("name")+"��X��\n"NOR,me);
        obj->delete_temp("invis"); 
        obj->delete_temp("hide"); 
    }
    return 1;
}


//---------------------------------|Snoop|---------------------------------
int do_snp(string arg)
{
   object ob;
   if(!arg) return notify_fail("�A�n��ť�֡H\n"); 
   if(ob = find_player(arg))
   "/cmds/wiz/snoop"->main(this_player(), ob->query("id"));
   return 1;
}


//---------------------------------|Clone other|---------------------------------
int do_dclone(string arg)
{
    object me,ob;
    me = this_player();
    if(!arg)
       return notify_fail(HIW+BLK"[���O]:clon <������|>\n"NOR); 
    if(!load_object(arg))
       return notify_fail("�S���o���ɮ�("+arg+".c)�C\n");
    ob = new(arg);
    if(!living(ob))
    {
      tell_object(me,ob->query("name")+"�ƻs���\\�M��b�A�����~��C\n");
      ob->move(me);
    }
    else
    {
      tell_object(me,ob->query("name")+"�ƻs���\\�M��b�o�өж��C\n");
      ob->move(environment(me));
    }
    message_vision("�u��$N�����Ť@���M�ܥX�F"+ob->query("name")+"�C\n",me);
    return 1;
}

//---------------------------------|Change Data|---------------------------------
// ����int��string���j��]�w
int do_change(string arg,int index)
{
   int i,vali;
   object obj;
   string *source_color;
   string *target_color;
   string score,user,vals;

   //int���
   if(arg && sscanf(arg, "%s %s to %d",user,score,vali) == 3)
   {
        if(obj = present(user, environment(this_player()))) "";
           else if(obj = find_player(user)) "";
           else if(obj = find_object(user)) "";
           else return notify_fail("�䤣�� " +user+ " �o�Ӫ���\n");
        printf("%s (\"%s\")->set(\"%s\", %d) = %d\n",file_name(obj),obj->query("name"),score,vali,vali);
        obj->set(score,vali);
        obj->save();
        return 1;
   }

   //string���
   else if(arg && sscanf(arg, "%s %s to %s",user,score,vals) == 3)
   {
        if(obj = present(user, environment(this_player()))) "";
           else if(obj = find_player(user)) "";
           else if(obj = find_object(user)) "";
           else return notify_fail("�䤣�� " +user+ " �o�Ӫ���\n");
        if(score == "name")
        { 
           if( strlen(vals) < 13 )
           { 
               printf("%s (\"%s\")->set(\"%s\", %s) = \"%s\"\n",file_name(obj),obj->query("name"),score,vals,vals);
               obj->set("name",vals);
               obj->save();
               return 1;
           }
           else
             { return notify_fail(HIR"[name]���i�j��6�Ӧr\n"NOR); }
        }
        source_color = keys(color);
        target_color = values(color);
        for(i=0;i<sizeof(source_color);i++)
           vals = replace_string(vals, source_color[i], target_color[i]);
        printf("%s (\"%s\")->set(\"%s\", %s) = \"%s\"\n",file_name(obj),obj->query("name"),score,vals,vals);
        obj->set(score,vals + NOR);
        obj->save();
        return 1;
    }

    //TEMP���
    else if( arg && sscanf(arg,"temp %s %s %d",user,score,vali) == 3 )
    {
        if(obj = present(user, environment(this_player()))) "";
           else if(obj = find_player(user)) "";
           else if(obj = find_object(user)) "";
           else return notify_fail("�䤣�� " +user+ " �o�Ӫ���\n");
        printf("%s (\"%s\")->set_temp(\"%s\", %d) = %d\n",file_name(obj),obj->query("name"),score,vali,vali);
        obj->set_temp(score,vali);
        obj->save();
        return 1;
    }
    else { return notify_fail(HIW+BLK"[���O]:"HIR"change"HIW+BLK" <����> <���> to <��>\n       "HIR"change temp"HIR+BLK" <����> <���> <��>\n"NOR); }

 write("�X�{���~�A�гq���ק�!!!\n");
 return 1;
}


//---------------------------------|Delete Data|---------------------------------
int do_delete(string arg)
{
      object obj;
      string del,user;

      if(arg && sscanf(arg, "%s about %s", user, del) == 2)
      {
         if(obj = present(user, environment(this_player()))) "";
           else if(obj = find_player(user)) "";
           else return notify_fail("�䤣�� " +user+ " �o�Ӫ���\n");
         printf("%s (\"%s\")->delete(\"%s\")\n",file_name(obj),obj->query("name"),del);
         obj->delete(del);
         obj->save();
         return 1;
      }
      if(arg && sscanf(arg, "%s temp %s", user, del) == 2)
      {
         if(obj = present(user, environment(this_player()))) "";
           else if(obj = find_player(user)) "";
         printf("%s (\"%s\")->delete_temp(\"%s\")\n",file_name(obj),obj->query("name"),del);
         obj->delete_temp(del);
         obj->save();
         return 1;
      }
      else { return notify_fail(HIW+BLK"[���O]:"HIR"delete"BLK" <�Y�H> <"HIR"about"HIW+BLK" || "HIR"temp"HIW+BLK"> <�ݩ�>  �ӧR����ƩμȦs���\n"); }
 write("�X�{���~�A�гq���ק�!!!\n");
 return 1;
}
