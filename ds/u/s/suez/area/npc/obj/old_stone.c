
inherit ITEM;
inherit F_UNIQUE;
void create()
{
set_name("古老的石雕",({"old stone","stone"}));
set_weight(1000);
set("unit","支");
set("long",
      " 稱這個為石雕其實是一種尊敬，因為這上面除了幾個\n"
      " 不知道用什麼東西刻的深紋外，根本沒啥東西。而且\n"
      " 絕對沒人會認為這是個藝術品。不過它的表面十分光\n"         
      " 滑，像打磨過的一樣。\n"
);   

set("replica_ob",__DIR__"ash");
setup();
}

