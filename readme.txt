jbooklet -- JBOOK の商品詳細ページの内容を元にアフィリエイトリンクを生成するプログラム
  作者: tsupo (H.Tsujimura,  mailto: tsupo@na.rim.or.jp)
  パッケージ作成日: 2009年3月31日
  パッケージ版数:   1.40

  このパッケージの説明:

    このパッケージには、以下のファイルが含まれています。

      readme.txt      いま、あなたが読んでいるファイル
      jbooklet.exe    JBOOK の商品詳細ページの内容を元にアフィリエイトリンクを生成するプログラム
      xmlRPC.dll      上記のプログラムを動かすのに必要なモジュール (サーバとの通信用)
      iconv.dll       同上 (文字コードの変換用) [このファイルの配布は GNU LGPL に従います]

      iconv-1.9.1.win32 以下のファイル
        Windows 用 の GNU iconv ライブラリ のバイナリパッケージ
        (GNU LIBRARY GENERAL PUBLIC LICENSE に基づく配布です)

  背景:
    私は、各種アフィリエイトリンクを拙作の「右クリック」シリーズ(Internet Explorler の MenuExt [右
    クリック拡張] を利用したスクリプト)を使って生成していますが、JBOOK に関しては、Webページが右ク
    リック禁止(ctrl キー や shift キー を使ったキーボードショートカットも禁止)状態に設定されている
    ため、「右クリック」シリーズが使えません。Internet Explorler を JavaScript を使用しない設定に
    すれば右クリックは使えるようになりますが、今度は肝心のスクリプト(JavaScript で記述)が動きません。
    そこで、Internet Explorler とは独立したツールとして、JBOOK の商品詳細ページの内容を解析し、アフィ
    リエイトリンクを生成するツールを作ってみました。

        * 「右クリック」シリーズについては http://watcher.moe-nifty.com/memo/menuext/ を参照
          してください。

    (2005年5月23日～25日に実施されたメインテナンス後は、右クリック禁止が解除されています。
     そのおかげで、「右クリック」で起動するスクリプトでも、JBOOK のアフィリエイトリンク生成処理を
     実現しようと思えば実現できるようになりました)


  配布条件:
    iconv.dll および iconv-1.9.1.win32 以下のファイル は、GNU LIBRARY GENERAL PUBLIC LICENSE にしたが
    います。
    それ以外のファイル(jbooklet.exe, xmlRPC.dll, および ドキュメント)は、tsupo の著作物です。
    配布は自由としますが、プログラムの動作および動作に伴い発生する諸々の事象に関しては無保証とします。

    書籍、雑誌等で本ツールの紹介を行なったり、本パッケージを収録したりする場合は、事前に連絡してくだ
    さい。

  動作環境:
    Windows 95,98,98SE,ME (Windows 95A 以降、できれば Windows 95 OSR2.0 以降推奨)
    Windows NT4.0SP6a, 2000, XP
    Windows Server 2000, Windows 2003 Server
    (proxy 経由で使う場合は、IE4.0 以降がインストール済みであることを推奨)
   ※ パーソナルファイアウォールを使用している場合は、別途、ファイアウォールの調整が
      必要な場合があります
   ※ 本ツールはインターネットに接続されている状態で使用します

  インストール:
    本アーカイブに収録されている jbooklet.exe, xmlRPC.dll, iconv.dll を同一のディレクトリ
    (フォルダ)に解凍し、ご利用ください。特に、必要な作業はありません。

  アンインストール:
    jbooklet.exe, xmlRPC.dll, iconv.dll, setting.inf を削除するだけです。レジストリはいじっ
    ていません。なお、setting.inf は、jbooklet.exe が自動生成する設定ファイルです。

  本ツールが生成するアフィリエイトリンク:
    jbooklet.exe が生成するアフィリエイトリンクは、バリューコマース(http://www.valuecommerce.ne.jp/)
    の商品リンク(マイリンクあるいは自由テキストリンクと呼ばれているもの)です。他のアフィリエ
    イトサービスには対応していません。また、JBOOK 専用のツールですので、それ以外の会社のアフィ
    リエイトリンク生成はできません。

    なお、JBOOK のアフィリエイトリンクを使用するには、前もってバリューコマースのアフィリエイ
    ト会員になった上で、さらに JBOOK のアフィリエイト参加承認を受ける必要があります。参加承認
    を受けた後、広告スペースを開設し、JBOOK の自由テキストリンクを使うように設定しておいてくだ
    さい。

    本ツールの生成したアフィリエイトリンクを実際に Web ページで使用する場合は、バリューコマース
    および JBOOK の規約、要請などにしたがって使用してください。

  使い方:
    jbooklet.exe
      アイコンをダブルクリック、または、DOSプロンプトから jbooklet [Enter] で起動します。
      まず、「バリューコマースのSID」と「バリューコマースのPID」を設定してください。
      SID はアフィリエイト会員の ID、PID は広告スペースの ID です。

        * SID、PID について
           広告スペースの設定をしたときに表示される HTML ソース、例えば

             <IFRAME frameBorder="0" allowTransparency="true" height="90" width="728"
             marginHeight="0" scrolling="no" src="http://ad.jp.ap.valuecommerce.com/
             servlet/htmlbanner?sid=1234567&pid=987654321" MarginWidth="0"><script 
             (以下、略)

           の sid= の後の数字、pid= の後の数字がそれぞれ SID、PID になります。
           (上記の例では SID は 1234567、PID は 987654321 になります)

      登録が終わったら、「商品詳細ページのURL」欄に、商品リンク作成対象ページの URL を入力し、変換ボ
      タンを押してください。変換に成功すると、「変換結果」欄に html ソースが出現しますので、ご自分の
      Webページ、blog 等に貼り付けてください。画像が使用可能な場合は、画像付きのリンクが生成されます。

        * 「商品詳細ページ」について
            JBOOK 内の、以下のような形式の URL のページのことです。
              (1) 新形式 (2005年5月26日～)
                http://www.jbook.co.jp/p/p.aspx/数字/s/
              (2) 旧形式
                http://www.jbook.co.jp/product.asp?isbn=数字
                http://www.jbook.co.jp/product.asp?isbn=数字-数字
                http://www.jbook.co.jp/product.asp?product=数字
                http://www.jbook.co.jp/product.asp?jan=数字
            これら以外の形式の URL のページのアフィリエイトリンク生成には対応していません。

      なお、本ツールによる各種設定内容は setting.inf という名前のファイルに保存されます。いったん設定
      を完全にクリアしたい場合は、setting.inf を削除した後、本ツールを起動してください。

      イントラネット内など、proxy サーバ経由でインターネットに接続する場合は、「proxy を使う」チェッ
      クボックスにチェックを入れて使用してください。Internet Explorer の proxy の設定を参照しますので、
      本ツール独自の proxy 設定を行なう必要はありません。

  バグ報告:
    このパッケージに含まれるプログラムの動作異常等、不具合を発見された方は、できるだけ詳細な報告を
      tsupo@na.rim.or.jp
    まで、電子メイルにて送付していただけると幸いです。

  サポート情報、1次配布元:
    本パッケージは、以下の URL にて配布しています。
        http://watcher.moe-nifty.com/memo/files/jbooklet.lzh
    以下の Webページに関連情報があります。
        http://watcher.moe-nifty.com/memo/2005/02/jbooklet.html

  更新情報:
    Ver 1.40  2008年 3月31日  (1) xmlRPC.dll を新しい版に入れ替えた
                              (2) 「バージョン情報」表示ダイアログを作り直した (表示する情報を増やし
                                  た)
    Ver 1.30  2006年10月10日  xmlRPC.dll の仕様変更に合わせて、jbooklet.exe も改定した。jbooklet.exe
                              自体の仕様は変更なし
    Ver 1.12  2005年11月15日  同梱の xmlRPC.dll を新しい版に入れ替えたのに伴い、リビルドし直した。
                              ソースの変更は行なっていない
    Ver 1.11  2005年 9月 3日  同梱の xmlRPC.dll を新しい版に入れ替えたのに伴い、リビルドし直した。
                              ソースの変更は行なっていない
   (Ver 1.10  2005年 6月 9日  ドキュメントのみ修正、追記)
    Ver 1.10  2005年 6月 8日  JBOOK の商品詳細ページの URL が新しい形式に変更されたのに対応するための
                              修正を実施
    Ver 1.00  2005年 2月24日  最初の公開版 「観測気球」にて公開
    Ver 0.91  2004年11月17日  仕様を Fix し、実際に運用試験を開始した版 
    Ver 0.90  2004年11月15日  最初の版

$Header: /comm/jbooklet/readme.txt 1     09/05/14 3:52 tsupo $
