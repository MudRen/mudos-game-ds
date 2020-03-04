// �����⵹ ppl �䴩�I����F... �A���a  wilfred@DS
// �p�G�n�䴩�I����n�]�t ansi2.h �~��ϥ�

#include <ansi2.h>
inherit ITEM;

mapping color = ([
/*
// ---- �I���� -----
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
*/
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

int do_color(string arg, int index);
int do_try(string arg);

void create()
{
  set_name(HIB"����"NOR, ({ "pill" }));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
    set("long","\n�o�O�@���������ĤY�A�O�]���b���W�ߨ쪺�C\n"
    	       "�ϥΤ�k�п�J�yhelp pill�z�C\n");
  setup();
}
int valid_user(object me)
{
        if(!wizardp(me))
                return notify_fail("�u���Ův�~��ΡC\n");
        return 1;
}
void init()
{
  add_action("do_change","change");
  add_action("do_help","help");
}

int do_change(string mess)
{
  if(!mess) return notify_fail("�A�Q����ԣ���H\n");
  if((mess!="min")&&(mess!="mout")&&(mess!="home")&&(mess!="rank")&&(mess!="clone")&&(mess!="dest"))
	return notify_fail("�S�o�ذ�...-.-�Y�C\n");
  this_player()->set_temp("wants",mess);
  write("�A�{�b�Q�n���ܪ��O"+this_player()->query_temp("wants")+"�C\n"
        "�Х�color���A��try���աC\n");
  add_action("do_try","try");
  add_action("do_color","color");
  return 1;
}
  
int do_try(string arg)
{
  if(!arg) return notify_fail("�п�J�z�Q�n����r.\n");
  do_color(arg,1);
  return 1;
}
int do_color(string arg, int index)
{
  object me = this_player(), ob = this_object();
  int i;
  string temp = arg;
  string *source_color;
  string *target_color;

  if(!arg) return notify_fail("�п�J�z�Q�n����r.\n");
  source_color = keys(color);
  target_color = values(color);

  for(i=0;i<sizeof(source_color);i++)
    temp = replace_string(temp, source_color[i], "");

/*  if( strlen(temp) > 16 )
  {
    write("System message: �̦h�u��ϥ� 16 �ӥb�Τ�r�A�C�⪺�ϥΫh���b�����C\n�Y�A�]�w����r���� 16 �ӥb�ΡA�h�t�Φ۰ʸɨ��ťզ� 16 �ӡC\n");
    return 1;
  }
  else
  {
    for(i=0;i<( 16 - strlen(temp) );i++)
      arg += " ";
  }
*/
  for(i=0;i<sizeof(source_color);i++)
    arg = replace_string(arg, source_color[i], target_color[i]);

  if(!index)
  {
    if(me->query_temp("wants") == "rank")
      me->set("guild_rank",arg + NOR);
    if(me->query_temp("wants") == "min")
      me->set("env/msg_min",arg + NOR);
    if(me->query_temp("wants") == "mout")
      me->set("env/msg_mout",arg + NOR);
    if(me->query_temp("wants") == "home")
      me->set("msg_home",arg + NOR);
    if(me->query_temp("wants") == "clone")
      me->set("env/msg_clone",arg + NOR);
    if(me->query_temp("wants") == "dest")
      me->set("env/msg_dest",arg + NOR);
    
    message_vision(HIW"\n$N�Y�U�@��$n"HIW"�A�ݰ_�Ӧn���ܺ������ˤl�C\n\n"NOR,me,ob);
    me->save();
    destruct(ob);
  }
  else write(NOR"���յ��G: �A��" +me->query_temp("wants")+ "�N�|�令 �y" +arg+ NOR"�z �C\n");
  return 1;
}

int do_help(string str)
{
  if(!str || str != "pill") return 0;
  write("\n�@���n���y�y���D�G\n"
  	"�o���ĤY�i�H���A�� "HIG"Guild-Rank �W�٤��C��C\n"NOR
  	"                     "HIG"msg_min�Amsg_mout���r��]�i�H�C\n"NOR
  	"                     "HIG"msg_home�Amsg_clone�Amsg_dest��M���ҥ~�C\n"NOR
  	"�A�W���k�� help nick�C\n\n"
  	HIC"���Ϊk: change message��\n"NOR
  	HIC"��message�i��rank,min,mout,home,clone,dest��\n"NOR);
  return 1;
}
