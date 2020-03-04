// auc.c
// Write by Wilfred@DS   2000/10/29
// Rewrite by wilfred@DS 2000/12/1
// ���ɶ��A�@�̨Τ�

#include <ansi.h>
#include <room.h>

#define AU_ROOM "/obj/void"
#define AUCMAN "�ݼ֩���(Aucman)"
#define PK_AREA "/open/world1/alickyuen/match/area"

inherit F_DBASE;

object item, owner, owner2;
object *inv, *goods;
string str1, str2;
int au1, au2, au3, amount, i, j;

// ���~��� -----------------
int item_space, item_durable;
string item_name;
// --------------------------

string space(int index);
string space_e(int index);
void auc_what(object who);
void reset_auc();
void tune_auc(object me);

void create()
{
  seteuid(getuid());
  set("no_clean_up",1);
  set("name","�ݼ֩���");
  set("id", "aucman");
}

int main(object who ,string arg)
{

  tune_auc(who);
  if(!arg) return notify_fail("�����D���榡�п�J help auc\n");
	if( environment(who)->query("no_auc") )
		return notify_fail("�������󵥤F�n�[�A"+AUCMAN+"�٨S�����......\n");
	if( strsrch(file_name(environment(this_player())), PK_AREA) != -1 )
		return notify_fail("�o�̤����auc���O�C\n");
	// auc settings by alickyuen@ds
  if( arg == "what" )
  {
    auc_what(who);
    return 1;
  }
  if( arg == "auto" )
  {
    au2 = au3 * 110 / 100;

    if( str2 == "over" ) return notify_fail("�{�b�èS�������󪫫~�C\n");
    if( who == owner || who == owner2) return notify_fail("�A����A�X���F�C\n");
    if(!environment(item)) return notify_fail("��椤�����~�X�F�@�ǰ��D�A�еy��C\n");
    if( who->query("bank/"+space_e(item_space)) < au2 ) return notify_fail("�A�S����h�s�ڡC\n");
    if( who->money_type() != item_space ) return notify_fail("�A�ҳB���ɪŻP��椤�����~���P�L�k�s���C\n");

    CHANNEL_D->do_channel( this_object(), "bala", HIG+AUCMAN+"�R"+
    "[" +space(item_space)+ "] ���H�X�� "HIY +au2+ HIG" ���R" +item_name+ HIG"[���p��" +item_durable+ "%]�A���S���H�n�[���H\n"NOR, users() );

    CHANNEL_D->do_channel( this_object(), "sys", who->query("id") + " �X�� " + au2 +"��\n"NOR, users() );

    remove_call_out("no_man1");
    remove_call_out("no_man2");
    remove_call_out("no_man3");
    remove_call_out("have_man");

    call_out("no_man1",10);

    owner2 = who;
    au3 = au2;
    return 1;
  }

  if( !str2 ) str2 = "over";
  if( sscanf(arg,"%s for %d", str1, au1) == 2)
  {
    if( str2 != "over" ) return notify_fail("�Х����o�����|�����C\n");

    reset_auc();
    sscanf(str1,"%d %s", amount, str1);
    if(!objectp(item = present(str1, who)) ) return notify_fail("�A�S���o�󪫫~�C\n");
    if(item->query_temp("invis")) return notify_fail("�A�S���o�󪫫~�C\n");
    if( item->query("equipped") ) return notify_fail("�A���˳Ƶ۳o�˪F��C\n");
    if( item->query("secured") ) return notify_fail("�а��O�s���A�C\n");

    if( !this_player()->money_type() ) return notify_fail("�A�ҳB���ɪŵL�k�i����C\n");
    if( item->query("money_id")   ||
        item->query("value") < 10 ||
        item->query("no_auc")     ||
        item->query("no_drop")    ||
        item->query("no_give")    ||
        item->query("no_sell")    ||
        item->is_character()
      )
    return notify_fail("�o�F�褣����I\n");

    if( amount )
    {
      if( amount > 50 ) return notify_fail("�@����檺�ƶq����W�L 50 �ӡC\n");
      inv = all_inventory(who);
      for(i=0;i<sizeof(inv);i++)
      {
        if(base_name(inv[i]) != base_name(item)) continue;
        j++;
      }
      if(j < amount) return notify_fail("�A�S���o��h���F��C\n");

      j = 0;
      for(i=0;i<sizeof(inv);i++)
      {
        if(base_name(inv[i]) != base_name(item)) continue;
        if(j >= amount) continue;
        goods[j] = inv[i];
        j++;
        inv[i]->move(AU_ROOM);
      }

      item_name = chinese_number(amount)+
                  item->query("unit")+item->query("name")+
                  "(" +item->query("id")+ ")"NOR;
    }
    else
    {
      item_name = item->query("name")+"("+item->query("id")+")"+NOR;
      item->move(AU_ROOM);
    }

    if(au1 < (item->query("value") * 70 / 100) )
    {
      tell_object(who, "�z��J�����B���~�A�t�Φ۰ʳ]�����~����� 70%�C\n");
      au1 = item->query("value") * 70 / 100;
    }
/*
      if(au1 > 100000 )
      {
        tell_object(who, "�z��J�����B�W�L����A�t�Φ۰ʳ]���W�� 100000 ���C\n");
        au1 = 100000;
      }
*/
    item_space = who->money_type();
    item_durable = item->query_durable();

    message_vision("\n\t�@�쨭���A�������A��M�ĹL�ӱN$N��" +item_name+ "�m���F�I\n\n",who);

    CHANNEL_D->do_channel( this_object(), "bala", HIG+AUCMAN+"�R"+
    "[" +space(item_space)+ "] ���H���" +item_name+ HIG"[���p��" +item_durable+ "%] ���� "HIC +(string)au1+ HIG" ���A���S���H�n�[���H\n"NOR, users() );
    CHANNEL_D->do_channel( this_object(), "sys", who->query("id") + "���X���C\n"NOR, users() );


    owner = who;
    owner2 = owner;
    au3 = au1;
    str2 = "yes";

    call_out("no_man1",10);

    return 1;
  }
  else
  {
    if( sscanf(arg,"%d %s", str1, au2) == 2 || sscanf(arg,"%d", au2) != 1) return notify_fail("�����D���榡�п�J help auc\n");
    if( str2 == "over" ) return notify_fail("�{�b�èS�������󪫫~�C\n");
    if( who == owner || who == owner2) return notify_fail("�A����A�X���F�C\n");
    if(!environment(item)) return notify_fail("��椤�����~�X�F�@�ǰ��D�A�еy��C\n");
    if( who->query("bank/"+space_e(item_space)) < au2 ) return notify_fail("�A�S����h�s�ڡC\n");
    if(au2 < (au3 * 110 / 100) ) return notify_fail("�C���s��������e�@���h 10% ��쪺�f���C\n");
    if( who->money_type() != item_space ) return notify_fail("�A�ҳB���ɪŻP��椤�����~���P�L�k�s���C\n");

    CHANNEL_D->do_channel( this_object(), "bala",HIG+AUCMAN+"�R"+
    "[" +space(item_space)+ "] ���H�X�� "HIY +au2+ HIG" ���R" +item_name+ HIG"[���p��" +item_durable+ "%]�A���S���H�n�[���H\n"NOR, users() );

    CHANNEL_D->do_channel( this_object(), "sys", who->query("id") + " �X�� " + au2 +"��\n"NOR, users() );

    remove_call_out("no_man1");
    remove_call_out("no_man2");
    remove_call_out("no_man3");
    remove_call_out("have_man");

    call_out("no_man1",10);

    owner2 = who;
    au3 = au2;
    return 1;
  }
}

int no_man1()
{
  CHANNEL_D->do_channel( this_object(), "bala",HIG+AUCMAN+"�R"+
  "[" +space(item_space)+ "] " +item_name+ HIG"[���p��" +item_durable+ "%] �s�� "HIC +au3+ HIG" ���Ĥ@���C\n"NOR, users() );

  call_out("no_man2",15);
  return 1;
}

int no_man2()
{
  CHANNEL_D->do_channel( this_object(), "bala",HIG+AUCMAN+"�R"+
  "[" +space(item_space)+ "] " +item_name+ HIG"[���p��" +item_durable+ "%] �s�� "HIC +au3+ HIG" ���ĤG���C\n"NOR, users() );

  if(owner == owner2)
    call_out("no_man3",10);
  else
    call_out("have_man",10);
  return 1;
}

int no_man3()
{
  CHANNEL_D->do_channel( this_object(), "bala",HIG+AUCMAN+"�R"+
  "[" +space(item_space)+ "] " +item_name+ HIG"�~�� "HIC +au3+ HIG" ���]�S�H�n�A��~~~~\n"NOR, users() );

  str2 = "over";

  if(!owner || !environment(owner) || owner->money_type() != item_space)
  {
    CHANNEL_D->do_channel( this_object(), "bala",HIG+AUCMAN+"�R"+
    "[" +space(item_space)+ "] " +item_name+ HIG"���쪫�D�X�F�I���D�A�����R���A�H�H�C\n"NOR, users() );
    if( amount )
    {
      for(i=0;i<amount;i++)
        destruct(goods[i]);
    }
    else destruct(item);
    return 1;
  }
  else
  {
    tell_object(owner, HIW"������A���D�G�y�藍�_�I�S�H�n�R���I�z"NOR);
    if(environment(item))
    {
      tell_object(owner, item_name+ HIW"��M���b�A���e�C\n"NOR);
      if( amount )
      {
        for(i=0;i<amount;i++)
          goods[i]->move(environment(owner));
      }
      else item->move(environment(owner));
    }
    else tell_object(owner, HIW"�i�O�z��" +item_name+ HIW"�]�����F�A�u��p�A�бz�h�ݰݧŮv�a�C\n"NOR);
    owner->save();
    return 1;
  }
}

int have_man()
{
  str2 = "over";
  if(!owner2                                           ||
     !environment(owner2)                              ||
     owner2->is_ghost()                                ||
     !item                                             ||
     !environment(item)                                ||
     owner2->money_type() != item_space                ||
     owner2->query("bank/" +space_e(item_space)) < au3
    )
  {
    CHANNEL_D->do_channel( this_object(), "bala",HIG+AUCMAN+"�R"+
    "[" +space(item_space)+ "] " +item_name+ HIG"�����|�X�F�@�I���D�A�]���������������|�C\n"NOR, users() );

    if(!owner || !environment(owner) || owner->money_type() != item_space)
    {
      CHANNEL_D->do_channel( this_object(), "bala",HIG+AUCMAN+"�R"+
      "[" +space(item_space)+ "] " +item_name+ HIG"���쪫�D�X�F�I���D�A�����R���A�H�H�C\n"NOR, users() );
      if( amount )
      {
        for(i=0;i<amount;i++)
          destruct(goods[i]);
      }
      else destruct(item);
      return 1;
    }
    else
    {
      tell_object(owner, HIW"������A���D�G�y�藍�_�I�R��]�ФF���A�`�ڥն]�@��I�z"NOR);
      if(environment(item))
      {
        tell_object(owner, item_name+ HIW"��M���b�A���e�C\n"NOR);
        if( amount )
        {
          for(i=0;i<amount;i++)
            goods[i]->move(environment(owner));
        }
        else item->move(environment(owner));
      }
      else tell_object(owner, HIW"�i�O�z��" +item_name+ HIW"�]�����F�A�u��p�A�бz�h�ݰݧŮv�a�C\n"NOR);
      owner->save();
      return 1;
    }
    return 1;
  }

  CHANNEL_D->do_channel( this_object(), "bala",HIG+AUCMAN+"�R"+
  "[" +space(item_space)+ "]" +item_name+ HIG"�H "HIC +au3+ HIG" ����X�A���´f�U�C\n"NOR, users() );

  tell_object(owner2, HIC"\n\t������M�X�{�b�A���e�A�N" +item_name+ HIC"��b�a�W�A�H�Y�K���F�C\n\n"NOR);
  tell_object(owner2, NOR+WHT"�t�Τv�۰ʱq�A���Ȧ�s�ڤ����� " +au3+ " "+space(item_space)+"�����C\n"NOR);
  if( amount )
  {
    for(i=0;i<amount;i++)
      goods[i]->move(environment(owner2));
  }
  else item->move(environment(owner2));

  owner2->add("bank/" +space_e(item_space), -au3);
  owner2->save();

  if(!owner || !environment(owner)) return 1;

  tell_object(owner,HIY "\n�������M������O�A�A�o�� " +(au3*95/100)+ " " +space(item_space)+ "�����A�v�s�i�z���Ȧ�̡C\n\n" NOR);
  owner->add("bank/" +space_e(item_space), (au3 * 95 / 100));
  owner->save();
  return 1;
}

string space(int index)
{
  switch(index)
  {
    case 1 : return "�j�N";
    case 2 : return "�{�N";
    case 3 : return "����";
    default : return "�ڤ�";
  }
}

string space_e(int index)
{
  switch(index)
  {
    case 1 : return "past";
    case 2 : return "now";
    case 3 : return "future";
    default : return "dream";
  }
}

void auc_what(object who)
{
  string msg = "";
  if( str2 == "over" )
  {
    tell_object(who, "�{�b�èS�������󪫫~�C\n");
    return;
  }

  msg += "  �ثe�ۻ�   " + au3+ "\n";
  msg += "  �������� " + item->query("value")+ "\n";
  msg += "  ���p       " + item->query_durable()+ "%\n";
  msg += "  ���ɪ�   " + space(item_space)+ "\n";
  msg += "  ���~�W     " + item->query("name")+ "(" +item->query("id")+ ")\n";

  if(item->query("skill_type"))
  msg += "  �����O     " + "�� " +item->query("weapon_prop/damage")+ "\n";

  if(item->query("armor_type"))
  msg += "  ���m�O     " + "�� " +item->query("armor_prop/armor")+ "\n";

  if(item->query_autoload())
  msg += "  ����        [�o��˳ƬO�i�H SAVE ��]\n";

  msg += "���~²���G   " + "\n" + item->query("long")+ "\n";

  tell_object(who, NOR+WHT"�H�U�O��椤���~���ԲӸ�ơG\n�СССССССССССССССССС�\n"NOR +msg+ NOR);
}

void reset_auc()
{
  amount = 0;
  goods = allocate(50);
  j = 0;
}

int help(object me)
{
  write(@HELP

  AUC ���O (�t���Ghelp channels)

   ���O�榡�G 1�N��檫�~��               <auc �F�� for ����>  
                                          <auc �ƶq �F�� for ����>
              2�N�s����                   <auc ����>
              3�N�d�ߩ�椤���~���ԲӸ�� <auc what>
              4�N�۰ʥs��                 <auc auto>

   ����椧�_���b ���~���70% ~ 100000 �����A�Ъ`�N�C��

HELP
);
  return 1;
}

void tune_auc(object me)
{
  string arg = "bala";
  string *tuned_ch = me->query("channels");

  if( pointerp(tuned_ch) && member_array(arg, tuned_ch) != -1 ) return;

  tuned_ch += ({ arg });
  me->set("channels", tuned_ch);
  me->save();
}
