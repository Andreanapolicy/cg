#pragma once
#include "./CEmptyShapeException.h"
#include "./CStyleNotExistException.h"
#include "./CWrongShapeIndexException.h"
#include "./CBorderGroupStyle.h"
#include "./CBorderStyle.h"
#include "./CFillGroupStyle.h"
#include "./IBorderStyle.h"
#include "./IGroup.h"

class CGroup : public IGroup, std::enable_shared_from_this<IGroup>
{
public:
	CGroup();

	size_t GetShapesCount() const override;
	std::shared_ptr<IShape> GetShapeAtIndex(const size_t index) override;
	void InsertShape(std::shared_ptr<IShape> shape, const size_t index) override;
	void RemoveShapeAtIndex(const size_t index) override;

	std::optional<FrameD> GetFrame() const override;
	void SetFrame(FrameD& frame) override;

	std::shared_ptr<IBorderStyle> GetLineStyle() override;
	std::shared_ptr<const IBorderStyle> GetLineStyle() const override;

	std::shared_ptr<IStyle> GetFillStyle() override;
	std::shared_ptr<const IStyle> GetFillStyle() const override;

	std::shared_ptr<const IGroup> GetGroup() const override;
	std::shared_ptr<IGroup> GetGroup() override;

	void Draw(ICanvas& canvas) const override;

private:
	bool IsFrameEmpty(FrameD& frame);
	std::vector<std::shared_ptr<IShape>> m_shapes;
	std::shared_ptr<IBorderStyle> m_borderStyle;
	std::shared_ptr<IStyle> m_fillStyle;
};
