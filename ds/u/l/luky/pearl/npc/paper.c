// An example book
inherit ITEM;
void create()
{
set_name("破紙片",({"paper"}));
set_weight(100);
set("unit","張");
set("long",@NOTE
這是一張被撕破的紙片.. 上面寫著:

  [七時七分] 地門崩裂
             
             欲入地獄必須先開地門, 當地門開啟 
             時, 百鬼夜行, 直衝天關......

  (開門口訣: 四方無極, 乾坤借法, 天地鬼神, 供我差使! )
  
NOTE
);
}
