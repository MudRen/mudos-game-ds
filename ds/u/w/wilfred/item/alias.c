inherit ITEM;
void create()
{
  set_name("啥東東",({"item"})); 
  set("long","看別人的 alias , 指令格式: p xxx");  setup();
}
void init()
{ add_action("p","p"); }
int p(string str)
{
  object ob; 
  int i;
  mapping alias;
  string *vrbs; 

  if(!str) return notify_fail("請輸入人名\n");  ob = find_player(str);   if(!ob) return notify_fail("找無此人\n");
  alias = ob->query_all_alias();
  if( !sizeof(alias) )
  {
    write(ob->name()+"目前並沒有設定任何 alias。\n");
    return 1;
  }
  else
  {
    write(ob->name()+"目前設定的 alias 有﹕\n");
    vrbs = keys(alias);
    vrbs = sort_array(vrbs, "sort_verb", this_object());
    for(i=0; i<sizeof(vrbs); i++)
    printf("%-15s = %s\n", vrbs[i], alias[vrbs[i]]);
    return 1;
  }
}

