inherit ITEM;
void create()
{
  set_name("ԣ�F�F",({"item"})); 
  set("long","�ݧO�H�� alias , ���O�榡: p xxx");  setup();
}
void init()
{ add_action("p","p"); }
int p(string str)
{
  object ob; 
  int i;
  mapping alias;
  string *vrbs; 

  if(!str) return notify_fail("�п�J�H�W\n");  ob = find_player(str);   if(!ob) return notify_fail("��L���H\n");
  alias = ob->query_all_alias();
  if( !sizeof(alias) )
  {
    write(ob->name()+"�ثe�èS���]�w���� alias�C\n");
    return 1;
  }
  else
  {
    write(ob->name()+"�ثe�]�w�� alias ���R\n");
    vrbs = keys(alias);
    vrbs = sort_array(vrbs, "sort_verb", this_object());
    for(i=0; i<sizeof(vrbs); i++)
    printf("%-15s = %s\n", vrbs[i], alias[vrbs[i]]);
    return 1;
  }
}

