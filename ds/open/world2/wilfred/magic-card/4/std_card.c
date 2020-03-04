#include <ansi2.h>
inherit ITEM;

string show_lv(int index);
string match(int index);

void setup()
{
  ::setup();
  set_name("[Magic]�ȵP",({"magic card","card"}));
  set("unit","�i");
  set("value",1);
}

int query_autoload() { return 1; }

string long()
{
  /*
                             <-- �W��� 10 x �a 10
      ��������������������   <-- ������������[�W�I����, �|�������@�ӤT����
      ���C��                 <-- �C�� string short = query("short")
      ����                   <-- �P�� int lv = query("lv")
      �� �ơơơơơơ� 
      ��                
      ��       ��            <-- �|�䪺�O�q�O int *pow = query("pow")
      ��     ��  ��              �]�w��k ({1,2,3,4})
      ��       ��                �O���ɰw�], �й�ӥ���
      ��                
      �� �b�b�b�b�b�b�b 
      ��  �\��  01��30       <-- �����W string ver_n = query("ver_n"), ���t�άݪ��ĴX�� int ver = query("ver")
      ���v�v�v�v�v�v�v�v�@       �d�� int num = query("num"), �t�~�@�Ӫ������w�W���� 30 �i�ҥH���γ]�F
                             <-- ���h������h�[�F���u
      �o�O�@���C��A���ɤ�   <-- �p�G�� set("long") �h string long = query("long"), �Ϥ� string long = query("name")
      ���䳣�ݪ���C

  */

  string msg, temp;
  string short, ver_n, long;
  string num;  // �j���ഫ����r
  int lv, *pow;

  if(query("long")) long = query("long");
    else long = query("short");

  if(query("num") < 10) num = " 0"+(string)query("num");
    else num = " "+(string)query("num");
  short  = query("short");
  ver_n = query("ver_n");
  lv    = query("lv");

  pow   = query("pow");

  temp =
  HBCYN+HIC"��������������������\n"
  HBCYN+HIC"��"NOR+HIW"%-16s"HBCYN+HIC"�j\n"
  HBCYN+HIC"��"HIW+BLK"%-16s"HBCYN+HIC"�j\n"
  HBCYN+HIC"��"NOR+HIC"�ơơơơơơơ�"HBCYN+HIC"�j\n"
  HBCYN+HIC"��"NOR"                "HBCYN+HIC"�j\n"
  HBCYN+HIC"��"NOR+HIW"%|16s"HBCYN+HIC"�j\n"
  HBCYN+HIC"��"NOR+HIW"%7s�@%-7s"HBCYN+HIC"�j\n"
  HBCYN+HIC"��"NOR+HIW"%|16s"HBCYN+HIC"�j\n"
  HBCYN+HIC"��"NOR"                "HBCYN+HIC"�j\n"
  HBCYN+HIC"�i"NOR+HIC+U"                "NOR+HBCYN+HIC"�j\n"
  HBCYN+HIC"�i"NOR"%|8s"HIY"%3s"NOR"/30�@"HBCYN+HIC"�j\n"
  HBCYN+HIC"���v�v�v�v�v�v�v�v�@\n"
  NOR+WHT"\n%s\n"NOR;

  msg = sprintf(temp,
  short, show_lv(lv), match(pow[0]), match(pow[3]), match(pow[1]), match(pow[2]), ver_n, num, long);

  return msg;
}

string show_lv(int index)
{
  int i;
  string msg = "";
  for(i=0;i<index;i++)
    msg += "��";
  return msg;
}

string match(int index)
{
  string *match = ({"��","��","��","��","��","��","��","��","��","��"});
  if(index >= sizeof(match)) return "��";
  return match[index];
}
