/// @file
/// SoundFont 2 Modulator class implementation.
///
/// @author gocha <https://github.com/gocha>

#include <sf2cute/modulator_item.hpp>

namespace sf2cute {

/// Constructs a new SFModulatorItem.
SFModulatorItem::SFModulatorItem() :
    identifier_(SFModulator(0), SFGenerator(0), SFModulator(0)),
    amount_(0),
    transform_op_(SFTransform(0)) {
}

/// Constructs a new SFModulatorItem using the specified controllers.
SFModulatorItem::SFModulatorItem(SFModulator source_op,
    SFGenerator destination_op,
    int16_t amount,
    SFModulator amount_source_op,
    SFTransform transform_op) :
    identifier_(std::move(source_op), std::move(destination_op), std::move(amount_source_op)),
    amount_(amount),
    transform_op_(transform_op) {
}

/// Returns the unique key of the modulator.
SFModulatorIdentifier SFModulatorItem::identifier() const {
  return identifier_;
}

/// Sets the unique key of the modulator.
void SFModulatorItem::set_identifier(SFModulatorIdentifier identifier) {
  identifier_ = std::move(identifier);
}

/// Returns the source of data for the modulator.
SFModulator SFModulatorItem::source_op() const {
  return identifier_.source_op();
}

/// Sets the source of data for the modulator.
void SFModulatorItem::set_source_op(SFModulator source_op) {
  identifier_.set_source_op(std::move(source_op));
}

/// Returns the destination of the modulator.
SFGenerator SFModulatorItem::destination_op() const {
  return identifier_.destination_op();
}

/// Sets the destination of the modulator.
void SFModulatorItem::set_destination_op(SFGenerator destination_op) {
  identifier_.set_destination_op(std::move(destination_op));
}

/// Returns the constant of modulation amount.
int16_t SFModulatorItem::amount() const {
  return amount_;
}

/// Sets the constant of modulation amount.
void SFModulatorItem::set_amount(int16_t amount) {
  amount_ = std::move(amount);
}

/// Returns the modulation source to be applied to the modulation amount.
SFModulator SFModulatorItem::amount_source_op() const {
  return identifier_.amount_source_op();
}

/// Sets the modulation source to be applied to the modulation amount.
void SFModulatorItem::set_amount_source_op(SFModulator amount_source_op) {
  identifier_.set_amount_source_op(std::move(amount_source_op));
}

/// Returns the transform type to be applied to the modulation source.
SFTransform SFModulatorItem::transform_op() const {
  return transform_op_;
}

/// Sets the transform type to be applied to the modulation source.
void SFModulatorItem::set_transform_op(SFTransform transform_op) {
  transform_op_ = std::move(transform_op);
}

} // namespace sf2cute
