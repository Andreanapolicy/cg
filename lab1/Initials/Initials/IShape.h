#pragma once
#include "./Frame.h"
#include "./IBorderStyle.h"
#include "./IStyle.h"
#include "./IDrawable.h"
#include <memory>
#include <optional>

class IGroup;

class IShape : public IDrawable
{
public:
	virtual std::optional<FrameD> GetFrame() const = 0;

	virtual void SetFrame(FrameD& frame) = 0;

	virtual std::shared_ptr<IBorderStyle> GetLineStyle() = 0;

	virtual std::shared_ptr<const IBorderStyle> GetLineStyle() const = 0;

	virtual std::shared_ptr<IStyle> GetFillStyle() = 0;

	virtual std::shared_ptr<const IStyle> GetFillStyle() const = 0;

	virtual std::shared_ptr<const IGroup> GetGroup() const = 0;

	virtual std::shared_ptr<IGroup> GetGroup() = 0;

	~IShape() = default;
};