inherit ITEM;
void create()
{
  set_name("�ѽL",({"chessboard"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","�@�Ӥ�s�ѽL�A�ѽL�W�e�F�Q�T���Q�T�����u�C");
    set("value",10);
  }
  setup();
}