inherit ITEM;
string get_short();
void create()
{
  set_name("�K����H��",({"broken mirror","mirror"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("basic_short","�K����H��");
    set("long",@LONG
�o�O�K����䤤�@�Ӥ�쪺�H���A��t�n���i�H���L�H���զX�A��
�A��s�F�b�ѫo�@�L���G�A���G���ݶ����K�Ӥ�줧�H���A�~��[�H�٭�C
LONG
);
    set("value",10);
  }
  setup();
}

void init()
{
  object me = this_player();
  if(query("changed")) return;
  if(!userp(me) && living(me)) call_out("accept_side",1,me);
}

void accept_side(object me)
{
  object ob = this_object();
  int index;
  if(!me) return;
  if(!userp(me) && living(me)) index = me->query("mirror_number");
  if(index) ob->set("accept_side",index);
  set_name(get_short(),({"broken mirror","mirror"}));
  set("changed",1);
  return;
}

string get_short()
{
  string temp, temp2 = this_object()->query("basic_short");
  switch(this_object()->query("accept_side"))
  {
    case 1 : temp = "��";
             break;
    case 2 : temp = "�S";
             break;
    case 3 : temp = "��";
             break;
    case 4 : temp = "��";
             break;
    case 5 : temp = "�[";
             break;
    case 6 : temp = "�_";
             break;
    case 7 : temp = "��";
             break;
    case 8 : temp = "�I";
             break;
    default : temp = "���w�q";
  }
  return temp2+ "[" +temp+ "]";
}

