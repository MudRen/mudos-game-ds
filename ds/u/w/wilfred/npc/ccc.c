inherit NPC;
void create()
{ set_name("���ܤH",({"banban"}));
  set("long",@LONG
���n�è�~~~~~~ �H�a�i�O�ܯ¼䪺~~~~~~
      �p�G�n�ϧڧ@�ʧ@, �Х� p xxx
      �n��ڪ�����W�r, �Х� cn xxx
      �n��ڪ��^��W�r, �Х� en xxx
LONG
);
  set("age",10);
  set("gender","�k��");
  set("level",1);
  setup(); }
void init()
{
if(geteuid(this_player()) != "wilfred") return;
 add_action("p","p");
  add_action("cn","cn");
  add_action("en","en"); }
int p(string str)
{ command(str);
  return 1; }
int cn(string str)
{   set_name(str,({query("id")}));
  return 1; }
int en(string str)
{  set_name(query("name"),({str}));
  return 1; }
