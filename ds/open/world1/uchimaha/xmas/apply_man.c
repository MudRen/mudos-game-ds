//
// Cosplay Show     Wilfred@DS  2000/12/25
//

#include <ansi2.h>
inherit NPC;

int obj_clone(string t, string l, int index);
string do_color(string arg);

mapping color = ([
"$HBWHT$" : HBWHT,
"$BBLK$"  : NOR+BBLK,
"$HBRED$" : HBRED,
"$BRED$"  : NOR+BRED,
"$HBGRN$" : HBGRN,
"$BGRN$"  : NOR+BGRN,
"$HBYEL$" : HBYEL,
"$BYEL$"  : NOR+BYEL,
"$HBBLU$" : HBBLU,
"$BBLU$"  : NOR+BBLU,
"$HBMAG$" : HBMAG,
"$BMAG$"  : NOR+BMAG,
"$HBCYN$" : HBCYN,
"$BCYN$"  : NOR+BCYN,
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

void create()
{
  set_name("�u�@�H��", ({"man"}) );
set("title",HIW"�t�ϸ` "HIG"C"HIW"os"HIG"p"HIW"lay "HIW"Show"NOR);
  set("race","human");
  set("age",25);
  set("level",1);
  set("gender", "�k��");

  set("long",@LONG
�L�O cosplay ���ʪ��u�@�H��, �A�i�H��J m_apply
�ӽ��ܸ˥Ϊ� EQ �� WP.
LONG
);
  set("chat_chance",10);
  set("chat_msg",({
(: command("say �t�� Cosplay Show (CP)�v�g�}�l, �z�i�H look man �d�ߨϥΤ�k��!") :),
(: command("smile") :),
(: command("say �п�u�|������, ���±z���X�@.") :),
(: command("sweat") :),
}) );

  set("no_kill",1);
  set("no_fight",1);
  set("no_cast",1);
  set("no_exert",1);
setup();
}

void init()
{
  add_action("do_apply","m_apply");
  add_action("do_help","help");
}

int do_apply(string str)
{
  string t, l;
  object obj;

  if(!str) return notify_fail("�����D�榡�� help m_apply\n");
  if( sscanf(str,"%s %s",t,l) != 2 ) notify_fail("�����D�榡�� help m_apply\n");

  message_vision(HIC"\n$N��$n�@�i cosplay show ���ӽЪ�C\n\n"NOR,this_player(),this_object());

  if( t != "id_card" )
  {
    if(!obj_clone(t,l,1))
      if(!obj_clone(t,l,2))
{
//      command("say �藍�_, �n���S���o�������� EQ �� WP ��...");
        command("say �藍�_, �n���S���o�������� EQ ��...");
        return 1;
      }
  }
  else
  {
    obj = new("/std/armor/neck.c");
    obj->set_name("�ѧO��" ,({ "id_card" }) );
    obj->set_weight(1);
    obj->set("armor_prop/name", ({do_color(l)}) );
    obj->set("armor_type","neck");
    obj->set("limit_con",2);
    obj->set("armor_prop/armor",1);
    obj->setup();
    obj->move(this_player());
  }

  command("smile");
  command("say �o�O�z�n���F��, ���z���o�r��!");

  return 1;
}

int obj_clone(string t, string l, int index)
{
  string error, bak = t;
  object obj, me = this_player();
  mapping attack;

  if(index == 1) t = "/std/armor/"+t+".c";
  if(index == 2) t = "/std/weapon/"+t+".c";
  if(index == 2)
  {
    command("say ��p, �ثe WP ���}��ӽ� ^.^");
    return 0;
  }

  if( file_size(t) < 0 ) return 0;
  if( !find_object(t) )
  {
    error = catch(call_other(t, "???"));
    if (error) return 0;
  }
  error = catch(obj = new(t));
if (error) return 0;
  if( !obj->move(me) )
  {
    destruct(obj);
    return 0;
  }

  obj->set_name(do_color(l),({bak}));
  obj->set_weight(1);
  obj->setup();
  if(index == 1)
  {
    obj->set("armor_type",bak);
    obj->set("limit_con",2);
    obj->set("armor_prop/armor",1);
  }

  // WP �����������D, �A�@��s

  if(index == 2)
  {
    obj->set("skill_type",bak);
    obj->set("verbs", ({ "hit" }) );
obj->set("actions", (: call_other, WEAPON_D, "query_action" :) );
    obj->set("material","unknow");
    obj->set("weapon_prop/damage",1);
    obj->set("flag",4);
    obj->set("limit_str",2);
  }

  return 1;
}

string do_color(string arg)
{
  object me = this_player(), ob = this_object();
  int i;
  string temp = arg;
  string *source_color;
  string *target_color;

  if(!arg) arg = "�Y��";
  source_color = keys(color);
  target_color = values(color);

  for(i=0;i<sizeof(source_color);i++)
temp = replace_string(temp, source_color[i], "");

  if( strlen(temp) > 20 )
  {
    write("System message: �̦h�u��ϥ� 20 �ӥb�Τ�r�A�L�h�h�y���ýX�A�Ӧ�X���ϥΫh���b�����C\n");
    return "�ýX";
  }

  for(i=0;i<sizeof(source_color);i++)
    arg = replace_string(arg, source_color[i], target_color[i]);

  arg += NOR;

  return arg;
}

int do_help(string str)
{
  string msg;
  if(str != "m_apply") return 0;

  write(@HELP

���ӽ� cosplay �D���
  ���O�榡: m_apply [�˳ƺ���] [�W��]

  �˳ƺ���: WP �� - �� fist      EQ �� - �� shield
                    �C sword             �� head
                    �M blade             �� mask
                    �� fork              �V neck(�t��: �ѧO�� id_card)
                    �P dagger            �� cloth
                    �� hammer            �� armor
                    �� axe               �� surcoat
                    �@ whip              �� wrists
                    �} bow               �x hands
                    �� staff             �� finger
                    �j gun               �y waist
                                         �� pants
                                         �H legging
                                         �c boots

  �ѧO�� id_card: �ݩ� neck ��, �]�w��W�٥Ψӧ��ܭӤH�ٸ�

  �W��: �ФŶW�L 20 �ӥb�Φr, �W���k�аѷ� help nick

HELP
);
 
  return 1;
}


