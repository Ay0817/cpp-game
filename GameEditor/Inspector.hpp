#ifndef INSPECTOR_HPP
#define INSPECTOR_HPP

#include <string>
#include <memory>
#include <unordered_map>

/*前方宣言*/
class GameObject;

/// @brief Editor 上で GameObject が持つ値を表示する。
/// @brief 値を入力することで対象の GameObejct の値を変更することができる。 
class Inspector final {
private:
	float rate;       // 倍率
	std::string name; // 項目名

	char x[10];     // x 座標
	char y[10];     // y 座標
	char scale[10]; // スケール
	char angle[10]; // 角度

	unsigned int prevID; // 前回選択された ID
	float prevX;         // 前回の x 座標の値
	float prevY;         // 前回の y 座標の値
	float prevScale;     // 前回の scale の値
	float prevAngle;     // 前回の angle の値

	/// @brief 
	/// @param x 新たな x 座標
	/// @param y 新たな y 座標
	/// @param scale 新たなスケール
	/// @param angle 新たな角度
	/// @param obj 値を変更する GameObject の参照先
	void value_update(float x, float y, float scale, float angle, const std::shared_ptr<GameObject>& obj) const;

	/// @brief 値を変更する前にセットアップを行う。
	/// @param obj 値を変更する GameObject の参照先
	void value_setup(const std::shared_ptr<GameObject>& obj);

	/// @brief 配列の要素が空だったとき用の対策
	/// @param buf 対象のバッファー
	void sanitize_buffer(char* buf);
public:
	/// @brief コンストラクタ
	[[nodiscard]] Inspector();

	/// @brief 描画処理
	/// @param obj Inspector に表示される GameObject の参照先
	void Draw(const std::shared_ptr<GameObject>& obj);
};

#endif
