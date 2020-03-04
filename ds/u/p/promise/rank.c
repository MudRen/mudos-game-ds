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

void create()
{
  set_name(MAG"�K�X�E�द"HIC"[�j�ƪ�]"NOR, ({ "purple pill","pill" }));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
    set("long","\n�U�s�ԧЪ��ԧQ�~�G \n�o�O�@���R�������𮧪��ĤY�A�Y�U�h�����|�o�ͤ���ơA�b�Y���e�̦n�D���ݤR�@�f(help pill)�C\n");
  setup();
}

void init()
{
  add_action("do_color","color");
  add_action("do_try","try");
  add_action("do_help","help"); 
  add_action("do_color2","change");}

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

  if( strlen(temp) > 16 )
  {
    write("System message: �̦h�u��ϥ� 16 �ӥb�Τ�r�A�C�⪺�ϥΫh���b�����C\n�Y�A�]�w����r���� 16 �ӥb�ΡA�h�t�Φ۰ʸɨ��ťզ� 16 �ӡC\n");
    return 1;
  }
  else
  {
  for(i=0;i<( 16 - strlen(temp) );i++)
      arg += " ";
  }

  for(i=0;i<sizeof(source_color);i++)
    arg = replace_string(arg, source_color[i], target_color[i]);

  if(!index)
  {
    me->set("guild_rank",arg + NOR);
    message_vision(HIW"\n$N�Y�U�@��$n"HIW"�A�y�ɳQ�@��"HIR"�C"HIG"�m"HIB"��"HIY"��"HIW"��¶�C\n\n�ܧ֪��A���ش��h�A$N�ݰ_�ө{�p��L������A���������C\n\n"NOR,me,ob);
  me->save();
    destruct(ob);
  }
  else write(NOR"���յ��G: �A�� Guild-Rank �N�|�令 �y" +arg+ NOR"�z �C\n");
  return 1;
}

int do_color2(string arg, int index)
{
  object ob = this_object(), sb = present(arg,environment(this_player()));
  int i;
  string temp = arg;
  string *source_color;
  string *target_color;

  if(!arg) return notify_fail("�п�J�z�Q�n����r.\n");
  source_color = keys(color);
  target_color = values(color);

  for(i=0;i<sizeof(source_color);i++)
    temp = replace_string(temp, source_color[i], "");

  if( strlen(temp) > 16 )
  {
    write("System message: �̦h�u��ϥ� 16 �ӥb�Τ�r�A�C�⪺�ϥΫh���b�����C\n�Y�A�]�w����r���� 16 �ӥb�ΡA�h�t�Φ۰ʸɨ��ťզ� 16 �ӡC\n");
    return 1;
  }
  else
  {
  for(i=0;i<( 16 - strlen(temp) );i++)
      arg += " ";
  }

  for(i=0;i<sizeof(source_color);i++)
    arg = replace_string(arg, source_color[i], target_color[i]);

  if(!index)
  {
    sb->set("guild_rank",arg + NOR);
    message_vision(HIW"\n$N�Y�U�@��$n"HIW"�A�y�ɳQ�@��"HIR"�C"HIG"�m"HIB"��"HIY"��"HIW"��¶�C\n\n�ܧ֪��A���ش��h�A$N�ݰ_�ө{�p��L������A���������C\n\n"NOR,ob);
  sb->save();
    destruct(ob);
  }
  else write(NOR"���յ��G: �A�� Guild-Rank �N�|�令 �y" +arg+ NOR"�z �C\n");
  return 1;
}

 
int do_help(string str)
{
  if(!str || str != "pill") return 0;
  write("\n�W�ѶǨӤ@���n�����D�G �o���ĤY�i�H���A�� "HIG"Guild-Rank �W�٤��C��"NOR"�A�W���k�� help nick�C\n\n"HIC"���Ϊk: color ��r��"NOR"\t\t"WHT"�p�G�n�ե�: try ��r,"HIW"��H�W�r�Х�color2\n\n"NOR);
  return 1;
}

