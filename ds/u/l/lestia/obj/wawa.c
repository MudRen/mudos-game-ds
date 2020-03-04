
inherit ITEM;
#include <ansi.h>

void create()
{
  set_name(HIM"������"NOR, ({ "bu wawa", "wawa" }) );
  set_weight(250);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "�@���i�R�G�u���p������,�A�i�H��L���A(nie shua)�C\n");
    set("unit", "��");
    set("value", 100000);
  }
  setup();
}

int init ()  
{   
  add_action ("do_setid", "setid");
  add_action ("do_setname", "setname");
  add_action ("do_nie", "nie");
  add_action ("do_shua", "shua");
  return 1;
}

int do_setid (string arg)
{
  object me = this_player();
  string name = this_object()->query("name");

  if (!wizardp(me))
  return 0;

  this_object()->set_name(name, ({ arg }) );
  return 1;
}

int do_setname (string arg)
{
  object me = this_player();

  if (!wizardp(me))
  return 0;

  this_object()->set("name",arg);
  this_object()->set("long","�@"+this_object()->query("unit")+arg+"�C\n");
  return 1;
}

int do_setunit (string arg)
{
  object me = this_player();

  if (!wizardp(me))
  return 0;

  this_object()->set("unit",arg);
  this_object()->set("long","�@"+arg+this_object()->query("name")+"�C\n");
  return 1;
}

string rdm(string *strs)
{
  return strs[random(sizeof(strs))];
}

int do_nie(string arg)
{
  string *dos = ({
    "�Τ�������@��",
    "�������F�@�U",
    "�p�ߦa���@��",
    "���@��",
    "���I�F�@�U",
    "�I�I",
    "�Τ���I�@�I",
  });

  string *parts = ({
    "���U",
    "�Y�o",
    "�y�J",
    "�D�|��",
    "�L�L",
    "�p�L�B",
    "�զ�",
    "�ܤ�",
    "������",
    "��l",
    "�p��y",
    "�U��",
    "�p��l",
    "��",
    "�޻K",
    "�L",
    "�}",
    "�{�{",
    "�p����",
  });

  string *actions = ({
    "�i�}�p�f�s�s�a�s�F���n�C",
    "�i�}�L�ڳ�F�@�n�C",
    "�ѯu�a�r�r�s�X�F�n���C",
    "�C�}�j�����a�֧a�֦a�w�F�X�U�C",
    "�ηN�a�g�a�C�C�C�}�@��j�����C",
    "�C�}�����A�S���N�a�X�W�����εۤF�C",
    "�n�F�n�Ӥj�����U�C",
    "�F�˦�n�a�V�O��_�j���U�C",
    "�{�u�a�I�I���U�C",
    "���ۤj�����ݵ�$N�C",
    "�b�b�a�ݵ�$N�A�Y�Y�a���X�n�ӡC",
    "��D�D��������L�̡A�@��m�l�@��ݵ�$N�C",
    "�⸣�U������@��ݤF�ݡA�S���Y�ݬ�$N�C",
    "�`�ۦa�⸣�U��$N�h�̤@�p�C",
    "�����a��j���U�K�b$N���W�C",
    "�K�F�@�K���ܡC",
    "�p���Y���a�K�F�@�K�B�Y�C",
    "�����a�Ⲵ���N���@���_�C",
    "���}�p�L�z�a�@�n���F�X�ӡC",
    "�\\�X�@�ƥi�R���p�W���y�C",
    "�i�}�p�L���o�ݤ��L��ӡC",
    "�N�۲����A�i�}�p�L���F�X�ӡC",
    "���e�@���C",
    "���r���r���r�C",
    "�r�r���a�ۤF�X�y�C",
    "�����a�ۤF�_�ӡG���P�ګ����K�K",
    "�۰_�n�x���G�κΧa�A�ĨĭC�K�K",
    "�������a���F���p�L�C",
    "���y����������ۤp�L��C",
    "���_�p�L�಴��@½��L�Y�h���z�H�F�C",
    "�Τp�⴪��$N���S�f�C",
    "�@�⴪��$N����A��������C",
    "����$N���Ⲵ�ڤڦa���$N�C",
    "���X����p�L�J�ý�F�X�U�C",
    "��_�@���p�L���b$N���y�W�C",
    "�����a�祴�ۨ���p�L��C",
    "��F��y�ϡC",
    "層F層p�����C",
    "��p�����V$N�@�n�C",
    "���F�_�ӡC",
    "���������Ӥ����C",
    "�O��$N����l���F�_�ӡC",
    "�����a�@���G���������A�ڭn���b�b�K�K",
    "�ѯu�a�ݡG�ڼ��Ӽb�b�n���n�r�H",
    "��$N�G�n�O�ڼ��Ӽb�b�A�O���O����w�ڧr�H",
    "��M�}�f���G�x�A���Ө������p�G�l�A�ګ��S���O�H",
    "���G��A�����Y�v�u���A���b�_�_���y�W�o�o�C�C",
    "�ݹD�G�p�_�_�ڤ���ɭԯ�����j�_�_���_�_�H",
    "���D�G�����A�n���nť�ڰۤ�q�H",
    "���D�G�_�_�Q�ۤ��q�A���@��O�H�ڷQ���_�ӭ���̦nť���C",
    "�ʹ�����a���G���������A�ڬO�ӳ̦n���p�ĨĭC�C",
    "�@�r�@�y�a���G�ڳ̨ĨĭC�A���������u���w�ڤ@�Ӥp�ĨĦn�ܡH",
    "�ۨ��ۻy�a���G�ڬO�p�ĨġA�p�ĨĬO�ڡC",
    "���n�Ӯ�a���G�p�ĨħڡK�K�Q�Y�}�}�C�C",
    "���G���ڼL�̩�@���}�}�n���n�H",
    "���G�������������]�N�ܡH�ܥX�}�}�Ӧn���n�H",
  });

  string str1 = "$N"+rdm(dos)+"$n��"+rdm(parts)+"�C\n";  
  string str2 = "$n"+rdm(actions)+"\n";
  
  if (arg != this_object()->query("id"))
  return 0;

  remove_call_out ("delayed_action");
  call_out ("delayed_action",1,str1,this_player(),this_object());
  remove_call_out ("delayed_reaction");
  call_out ("delayed_reaction",3,str2,this_player(),this_object());
  return 1;
}

int do_shua (string arg)
{
  object me = this_object();
  object who;
  string my_name = me->query("name");
  string *dos = ({
    "���֦a�q$N�⤤�]�U�ӡA����$n��",
    "�q$N���W�ƤU�ӡA�O��$n��",
    "�q$N�⤤�ϫl��$n���W�@���A�K�b$n��",
    "��$N�I�I�Y�A�@�ਭ���b$n��",
    "�|�N�a����$n��",
    "�ѽm�a����$n��",
    "���������a�ۨ�$n��",
    "�@�Ӽu������$n��",
    "���W$n��",
    "�I�a�@���A�D�b$n��",
    "�@�Ӥp�����D�b$n��",
    "���l�@�{�A�w���b$n��",
    "�����a�@½���A��b$n��",
    "���F�a��b$n��",
  });

  string *parts = ({
    "�ḣ�c",
    "�󸣪�",
    "���Y�v",
    "�r�Y",
    "���w��",
    "�ѹ���",
    "�|��",
    "���y�J",
    "�p�L�B",
    "���}���L��",
    "�Φզ�",
    "�j�ɤ�",
    "�s�V��l",
    "�e���",
    "�ΤU��",
    "�װs��",
    "�n��l",
    "�G�ﵲ",
    "��ӻH",
    "����",
    "�u���",
    "�δx",
    "����",
    "�k��",
    "�޻K�y",
    "�G�ư�",
    "�p�L",
    "�u�L",
    "�j�L",
    "����Ҥj�L",
    "ù��L",
    "���a�L",
    "����y",
    "�n�ʸy",
    "���D�y",
    "�����Z�y",
    "�ª�y",
    "�b�O��I",
    "�}���",
    "�q�}�I",
    "�j�}�k",
    "�Ӹ}�y",
    "�j�{��",
    "��s�Ψ{",
    "ç�{��",
    "�m�I",
    "���v",
    "�v�y",
  });

  string *actions = ({
    "���Ȯ�a���t���F�@�p�y���C",
    "�ݰ_�p���j�N�g��@��C",
    "�A�F�@�p�f�C",
    "�R�X�@�p�����ߪ��f���}��C",
    "�i�f�N�Q�F�X�f�C",
    "�N$n�Q�o���h���ӡC",
    "�i�}�p�L�r�F�@�f�C",
    "�i�}�p�L�r��$n��������C",
    "�r�U�@�p���סC",
    "�r�U�@�j�����D�סC",
    "�r�o$n���ݹy�����R�ۮQ�C",
    "�r�X��Ƭ����L��C",
    "�r�X�@�j����嵵�͡C",
    "���U�@����C",
    "���U�@�h�ѥ֡C",
    "���@���Ӥ򤣩�C",
    "�w�O��X�@�Ӧ��n��Ī�C",
    "�a�֧a�֨ϫl���F�X���C",
    "���X�@�Ӥj�n�~�C",
    "�J�ý�F�X�U�C",
    "��o$n�W�R�U�n�C",
    "�y�a�@�n�𤤭n�`�C",
    "��o$n��½�ղ��C",
    "�Τj���U�F�a�@���C",
    "�Τp����X�X��¸��]�K�C",
    "�ϫl�a��X���D�岪�C",
    "��X������w�C",
    "���X���⪱�R�a�@�t�C",
    "�r�������a�t��$n���H���C",
    "���X���t�X�n�j�@�Ӹ~���C",
    "�������d�C",
    "�԰ԥ��k�}�}���F�Q�X�U�C",
    "���F�Ө⭱���C",
    "�@���Ȯ�a���_�}�}��C",
    "���X�@�j�����Y��l�C",
    "�Τp�����X�@�p�~�w�C",
    "�Τ����X�@�F�H�C",
    "�ǥX�@�����͡C",
    "��X�@�j���C�K���R���C",
  });

  string *returns = ({
    "�M��]�^$N���W�C",
    "�M�ᮨ���a�^��$N�⤤�C",
    "�A�^�Y�@�����g�a����$N���W�C",
    "�A�a���D�^��$N�⤤�C",
    "�A�^�Y�@���A�D��$N���W�C",
    "�M�ᰪ���a�^��$N�⤤�C",
    "�M��o�N�a�p�^$N���W�C",
    "�M��Q�����N�a�p�^$N�⤤�C",
    "�M�ῳ�Ħa�ۦ^$N���W�C",
    "�M��Y�߭Y�g�a�ۦ^$N�⤤�C",
  });

  string str1 = my_name+rdm(dos)+rdm(parts)+"�W�A"+rdm(actions)+"\n";
  
  if (! arg)
    return 0;

  who = present(arg,environment(this_player()));

  if (! who)
  return notify_fail ("�A�֡H\n");

  message_vision ("$N�V"+my_name+
  "�ϤF�@�Ӳ���A�M��Y�L��Ʀa�ݤF$n�@���C\n",this_player(),who);
  remove_call_out ("delayed_action");
  call_out ("delayed_action",3,str1,this_player(),who);
  remove_call_out ("delayed_reaction");
  call_out ("delayed_reaction",4,rdm(returns)+"\n",this_player(),who);
  return 1;
}

void delayed_action (string str, object ob1, object ob2)
{
  message_vision (str,ob1,ob2);
}

void delayed_reaction (string str, object ob1, object ob2)
{
  message_vision (str,ob1,ob2);
}

