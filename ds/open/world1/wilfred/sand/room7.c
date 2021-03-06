inherit ROOM;
void create()
{
  set ("short", "靜心亭");
  set ("long", @LONG
這是一座用竹子撘建的涼亭，亭中擺了竹桌竹椅，擺設簡單大方
，亭子周圍種滿了青翠的竹子，旁邊還有一個小池塘，由此可看出這
亭子主人的閒情逸致。
LONG
);

  set("exits", ([
  "south" : __DIR__"room6",
]));
  set("objects", ([
  __DIR__"npc/npc29" : 1,
]));
  set("no_clean_up", 0);
  set("light",1);
  setup();
}

int room_effect(object me)
{
  switch(random(7))
  {
    case 1 : tell_room(this_object(),"一陣涼風吹來，輕拂著每個人的臉頰。\n");
             break;
    case 2 : tell_room(this_object(),"竹林在風中輕輕的搖曳著，竹葉沙沙作響。\n");
             break;
    case 3 : tell_room(this_object(),"池塘中的魚忽然探出頭來，隨即又潛回水裡。\n");
             break;
    default : return 1;
  }
  return 1;
}

void reset()
{
  object npc;
  if(objectp(npc = find_living("astronomy")))
    if(!npc->query_temp("game_now") && !npc->query_temp("get_match_now")) destruct(npc);
      else return;
  ::reset();
  return;
}
